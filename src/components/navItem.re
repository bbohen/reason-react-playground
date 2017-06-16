let component = ReasonReact.statelessComponent "NavItem";
let make ::isActive ::route _children => {
	...component,
	render: fun _state _self => {
		let className = isActive ? "nav-item active" : "nav-item";
		<a
			className={className}
			href={"#/" ^ route}
		>
			(ReactRe.stringToElement route)
		</a>
	}
};
