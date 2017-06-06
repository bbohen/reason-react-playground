module ItemList = {
    include ReactRe.Component;
    type props = {
        items: list string
    };
    let name = "ItemList";
    let render {props} => {
        let items = 
            props.items |>
            List.map (
                fun item =>
                    <li>(ReactRe.stringToElement item)</li>
            );
        <ul>
            (ReactRe.arrayToElement (Array.of_list items))
        </ul>;
    };
};

include ReactRe.CreateComponent ItemList;

let createElement ::items => wrapProps{items: items}