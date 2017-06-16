let component = ReasonReact.statelessComponent "Hackernews";
let make _children => {
	...component,
	render: fun _state _self => {
		<h1>(ReactRe.stringToElement "Hackernews")</h1>
	}
}
