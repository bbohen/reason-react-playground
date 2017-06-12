module Hackernews = {
  include ReactRe.Component;
	type props = unit;
  let name = "Hackernews";
  let render _componentBag =>
		<h1>(ReactRe.stringToElement "Hackernews")</h1>
};

include ReactRe.CreateComponent Hackernews;

let createElement = wrapProps ()
