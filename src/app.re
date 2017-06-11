module App = {
  include ReactRe.Component.Stateful;
	type props = unit;
  type state = {
    currentInput: TodoList.todo,
    todos: list TodoList.todo,
		totalTodoCount: int
  };
  let name = "App";
  let getInitialState _props => {
		let todos = Persist.loadLocally "todos";
    {
      currentInput: {
				id: "",
				name: ""
			},
      todos,
			totalTodoCount: List.length todos
    }
  };
  let handleSubmit {state} event => {
    ReactEventRe.Form.preventDefault event;
    let todos = state.todos @ [state.currentInput];
		Persist.saveLocally todos "todos";
    Some {
      currentInput: {
				id: "",
				name: ""
			},
      todos,
			totalTodoCount: state.totalTodoCount + 1
    }
  };
	let handleTodoClick {state} todoId => {
		let todos = List.filter (fun todo => not (TodoList.(todo.id) === todoId)) state.todos;
		Persist.saveLocally todos "todos";
		Some {
			...state,
			todos
		}
	};
  let handleInputChange {state} event => {
    Some {
      ...state,
			currentInput: {
				id: "id-" ^ string_of_int state.totalTodoCount,
				name: (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value
			}
    }
  };
  let render {state, updater} => {
    let { currentInput, todos } = state;
		let hasTodos = List.length todos > 0;
		let message = hasTodos ? "What else would you like to do?" : "What would you like to do?";
    <div>
      <form id="todoform" onSubmit=(updater handleSubmit)>
        <input
          _type="text"
					id="newtodo"
					autoComplete="off"
          placeholder={message}
          onChange=(updater handleInputChange)
          value={currentInput.name}
        />
      </form>
      <TodoList onTodoClick={updater handleTodoClick} items={todos} />
    </div>;
  }
};

include ReactRe.CreateComponent App;

let createElement = wrapProps ()
