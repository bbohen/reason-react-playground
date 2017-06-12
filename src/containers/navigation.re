module Navigation = {
  include ReactRe.Component;
	type props = {
		route: string
	};
  let name = "Navigation";
  let render {props} =>
		<nav>
			<div>
				<NavItem route="todos" isActive={props.route === "todos"} />
				(ReactRe.stringToElement " | ")
				<NavItem route="hackernews" isActive={props.route === "hackernews"} />
			</div>
		</nav>;
};

include ReactRe.CreateComponent Navigation;

let createElement ::route => wrapProps{route: route};
