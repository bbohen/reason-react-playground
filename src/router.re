let component = ReasonReact.statelessComponent "Router";

let make ::route _children => {
	...component,
	render: fun _state _self => {
		switch route {
		| "todos" => <TodoList />
		| "hackernews" => <Hackernews />
		| _ => <TodoList />
		}
	}
}

