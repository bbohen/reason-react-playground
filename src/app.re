module App = {
  include ReactRe.Component.Stateful;
  type props = {
    greeting: string
  };
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
  let render {props, state, updater} => {
    let { currentInput, todos } = state;
    <div>
      <p>(ReactRe.stringToElement props.greeting)</p>
      <form onSubmit=(updater handleSubmit)>
        <input
          _type="text"
          placeholder="Add something to the list"
          onChange=(updater handleInputChange)
          value={currentInput}
        />
      </form>
      <ItemList items={todos} />
    </div>;
  }
};

include ReactRe.CreateComponent App;

let createElement ::greeting => wrapProps {greeting: greeting};