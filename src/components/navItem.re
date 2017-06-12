module NavItem = {
	include ReactRe.Component;
	type props = {
		isActive: bool,
		route: string
	};
	let name = "NavItem";
	let render {props} => {
		let className = props.isActive ? "nav-item active" : "nav-item";
		<a
			className={className}
			href={"#/" ^ props.route}>
			(ReactRe.stringToElement props.route)
		</a>
	}
};

include ReactRe.CreateComponent NavItem;

let createElement ::isActive ::route => wrapProps{isActive: isActive, route: route}
