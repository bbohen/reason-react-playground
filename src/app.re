module App = {
    include ReactRe.Component;
    type props = {
        greeting: string
    };
    let name = "App";
    let items = [
        "hello",
        "there",
        "world"
    ];
    let render {props} =>
        <div>
            <p>(ReactRe.stringToElement props.greeting)</p>
            <input
                _type="text"
                placeholder="test"
            />
            <ItemList items={items} />
        </div>;
};

include ReactRe.CreateComponent App;

let createElement ::greeting => wrapProps {greeting: greeting};