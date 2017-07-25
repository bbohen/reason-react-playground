type listItem = {id: int, name: string};

let component = ReasonReact.statelessComponent "ListView";

let make ::items ::onItemClick _children => {
  ...component,
  render: fun _self => {
    let itemsToRender =
      items |>
      List.map (
        fun item =>
          <li onClick=(fun _ => onItemClick item.id) key=(string_of_int item.id)>
            (ReasonReact.stringToElement item.name)
          </li>
      );
    <ul id="list"> (ReasonReact.arrayToElement (Array.of_list itemsToRender)) </ul>
  }
};
