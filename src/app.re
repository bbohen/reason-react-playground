module App = {
  include ReactRe.Component.Stateful;
	type props = unit;
	type state = {
		route: string
	};
  let name = "App";
	let getInitialState _props => {
		route: "/"
	};
	let componentDidMount {updater} => {
		let routeHandler _componentBag route => {
			Some {route: route}
		};
		let director = DirectorRe.makeRouter {
			"/:wildcard": updater routeHandler
		};
		DirectorRe.init director "/";
		None
	};
  let render {state} =>
		<main>
			<Navigation route={state.route} />
			<section>
				<Router route={state.route} />
			</section>
		</main>
};

include ReactRe.CreateComponent App;

let createElement = wrapProps ()
