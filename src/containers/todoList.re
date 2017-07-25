type state = {currentInput: ListView.listItem, todos: list ListView.listItem};

let component = ReasonReact.statefulComponent "TodoList";

let make _children => {
  let submit event {ReasonReact.state: state} => {
    ReactEventRe.Form.preventDefault event;
    let todos = state.todos @ [state.currentInput];
    Persist.saveLocally todos "todos";
    ReasonReact.Update {currentInput: {id: Random.int 1000, name: ""}, todos}
  };
  let click todoId {ReasonReact.state: state} => {
    let todos = List.filter (fun todo => not (ListView.(todo.id) === todoId)) state.todos;
    Persist.saveLocally todos "todos";
    ReasonReact.Update {...state, todos}
  };
  let change event {ReasonReact.state: state} =>
    ReasonReact.Update {
      ...state,
      currentInput: {
        id: state.currentInput.id,
        name: (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value
      }
    };
  {
    ...component,
    initialState: fun () => {
      let todos = Persist.loadLocally "todos";
      {currentInput: {id: Random.int 1000, name: ""}, todos}
    },
    render: fun self => {
      let {currentInput, todos} = self.state;
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
