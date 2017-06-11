type listItem = {id: string, name: string};

module ListView = {
  include ReactRe.Component;
  type props = {
    items: list listItem,
		onItemClick: string => unit
  };
  let name = "ListView";
  let render {props} => {
    let items =
      props.items |>
      List.map (
        fun item =>
          <li onClick={fun _ => props.onItemClick (item.id)} key={item.id}>
						(ReactRe.stringToElement item.name)
					</li>
      );
      <ul id="list">
        (ReactRe.listToElement items)
      </ul>;
    };
};

include ReactRe.CreateComponent ListView;

let createElement ::items ::onItemClick => wrapProps{items: items, onItemClick: onItemClick}
