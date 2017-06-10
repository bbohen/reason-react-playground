module TodoList = {
  include ReactRe.Component;
  type props = {
    items: list string
  };
  let name = "TodoList";
  let render {props} => {
    let items =
      props.items |>
      List.map (
        fun item =>
          <li>(ReactRe.stringToElement item)</li>
      );
      <ul id="todolist">
        (ReactRe.listToElement items)
      </ul>;
    };
};

include ReactRe.CreateComponent TodoList;

let createElement ::items => wrapProps{items: items}
