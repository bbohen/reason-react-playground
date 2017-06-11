module App = {
  include ReactRe.Component;
	type props = unit;
  let name = "App";
  let render _componentBag => <TodoList />
};

include ReactRe.CreateComponent App;

let createElement = wrapProps ()
