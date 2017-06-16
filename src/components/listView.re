type listItem = {id: string, name: string};

let component = ReasonReact.statelessComponent "ListView";
let make ::items ::onItemClick _children => {
	...component,
	render: fun _state _self => {
    let itemsToRender =
      items |>
      List.map (
        fun item =>
          <li
						onClick={fun _ => onItemClick (item.id)}
						key={item.id}
					>
						(ReactRe.stringToElement item.name)
					</li>
    	);
		<ul id="list">
			(ReactRe.listToElement itemsToRender)
		</ul>;
	}
};

