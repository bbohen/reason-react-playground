module Router = {
	include ReactRe.Component;
	type props = {
		route: string
	};
	let name = "Router";
	let render {props} => {
		switch props.route {
			| "todos" => <TodoList />
			| "hackernews" => <Hackernews />
			| _ => <TodoList />
		};
	}
};

include ReactRe.CreateComponent Router;

let createElement ::route => wrapProps{route: route};

