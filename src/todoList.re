type todo = {id: string, name: string};

module TodoList = {
  include ReactRe.Component;
  type props = {
    items: list todo
  };
  let name = "TodoList";
  let render {props} => {
    let items =
      props.items |>
      List.map (
        fun item =>
          <li key={item.id}>
						(ReactRe.stringToElement item.name)
					</li>
      );
      <ul id="todolist">
        (ReactRe.listToElement items)
      </ul>;
    };
};

include ReactRe.CreateComponent TodoList;

let createElement ::items => wrapProps{items: items}
