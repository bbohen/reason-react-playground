let component = ReasonReact.statelessComponent "Navigation";
let make ::route _children => {
	...component,
	render: fun _state _self =>
		<nav>
			<div>
				<NavItem route="todos" isActive={route === "todos"} />
				(ReactRe.stringToElement " | ")
				<NavItem route="hackernews" isActive={route === "hackernews"} />
			</div>
		</nav>
};
