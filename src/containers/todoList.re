type state = {currentInput: ListView.listItem, todos: list ListView.listItem, totalTodoCount: int};

let component = ReasonReact.statefulComponent "TodoList";

let make _children => {
  let submit event state _self => {
    ReactEventRe.Form.preventDefault event;
    let todos = state.todos @ [state.currentInput];
    Persist.saveLocally todos "todos";
    ReasonReact.Update {
      currentInput: {id: "", name: ""},
      todos,
      totalTodoCount: state.totalTodoCount + 1
    }
  };
  let click todoId state _self => {
    let todos = List.filter (fun todo => not (ListView.(todo.id) === todoId)) state.todos;
    Persist.saveLocally todos "todos";
    ReasonReact.Update {...state, todos}
  };
  let change event state _self =>
    ReasonReact.Update {
      ...state,
      currentInput: {
        id: "id-" ^ string_of_int state.totalTodoCount,
        name: (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value
      }
    };
  {
    ...component,
    initialState: fun () => {
      let todos = Persist.loadLocally "todos";
      {currentInput: {id: "", name: ""}, todos, totalTodoCount: List.length todos + 1}
    },
    render: fun state self => {
      let {currentInput, todos} = state;
      let hasTodos = List.length todos > 0;
      let message = hasTodos ? "What else would you like to do?" : "What would you like to do?";
      <div>
        <form id="todoform" onSubmit=(self.update submit)>
          <input
            _type="text"
            id="newtodo"
            autoComplete="off"
            placeholder=message
            onChange=(self.update change)
            value=currentInput.name
          />
        </form>
        <ListView onItemClick=(self.update click) items=todos />
      </div>
    }
  }
};
