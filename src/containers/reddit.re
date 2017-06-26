let component = ReasonReact.statelessComponent "Reddit";
let make ::posts _children => {
	...component,
	render: fun _state _self => {
	let itemsToRender =
		posts |>
		Array.map (
			fun (postItem: RedditData.post) =>{
				Js.log(postItem);
				<li
					key={postItem.data.id}
				>
					(ReactRe.stringToElement postItem.data.title)
				</li>
			}
		);
	<div>
		<h1>(ReactRe.stringToElement "r/reasonml")</h1>
		<ul id="list">
			(ReactRe.arrayToElement itemsToRender)
		</ul>
	</div>
	}
}
