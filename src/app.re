module App = {
  include ReactRe.Component.Stateful;
	type props = unit;
  type state = {
    currentInput: string,
    todos: list string
  };
  let name = "App";
  let getInitialState _props => {
    {
      currentInput: "",
      todos: []
    }
  };
  let handleSubmit {state} event => {
    ReactEventRe.Form.preventDefault event;
    let todos = state.todos @ [state.currentInput];
    Some {
      currentInput: "",
      todos
    }
  };
  let handleInputChange {state} event => {
    Some {
      ...state,
      currentInput: (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value
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
          value={currentInput}
        />
      </form>
      <TodoList items={todos} />
    </div>;
  }
};

include ReactRe.CreateComponent App;

let createElement = wrapProps ()
