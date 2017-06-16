type state = {
	route: string
};

let component = ReasonReact.statefulComponent "App";
let make _children => {
	...component,
	initialState: fun () => { route: "/" },
	didMount: fun _state self => {
		let routeHandler route _state _self => ReasonReact.Update {route: route};
		let director = DirectorRe.makeRouter {
			"/:wildcard": self.update routeHandler
		};
		DirectorRe.init director "/";
		ReasonReact.NoUpdate;
	},
	render: fun {route} _self =>
		<main>
			<Navigation route={route} />
			<section>
				<Router route={route} />
			</section>
		</main>
};
