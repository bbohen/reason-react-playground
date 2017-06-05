module App = {
    include ReactRe.Component;
    type props = unit;
    let name = "The App";
    let render _componentBag =>
        <div> (ReactRe.stringToElement "Hello World!") </div>;
};

include ReactRe.CreateComponent App;

let createElement = wrapProps ();