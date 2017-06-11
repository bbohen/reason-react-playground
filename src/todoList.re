type todo = {id: string, name: string};

module TodoList = {
  include ReactRe.Component;
  type props = {
    items: list todo,
		onTodoClick: string => unit
  };
  let name = "TodoList";
  let render {props} => {
    let items =
      props.items |>
      List.map (
        fun item =>
          <li onClick={fun _ => props.onTodoClick (item.id)} key={item.id}>
						(ReactRe.stringToElement item.name)
					</li>
      );
      <ul id="todolist">
        (ReactRe.listToElement items)
      </ul>;
    };
};

include ReactRe.CreateComponent TodoList;

let createElement ::items ::onTodoClick => wrapProps{items: items, onTodoClick: onTodoClick}
