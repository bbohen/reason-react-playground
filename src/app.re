module App = {
    include ReactRe.Component;
    type props = unit;
    let name = "The App";
    let render {props, updater} =>
        <div> (ReactRe.stringToElement "Hello World") </div>;
};

include ReactRe.CreateComponent App;

let createElement = wrapProps ();