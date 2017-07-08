let component = ReasonReact.statelessComponent "Reddit";

let make ::posts _children => {
  ...component,
  render: fun _self => {
    let itemsToRender =
      posts |>
      Array.map (
        fun (postItem: RedditData.post) =>
          <li key=postItem.data.id>
            <a href=postItem.data.url target="_blank">
              (ReasonReact.stringToElement postItem.data.title)
            </a>
          </li>
      );
    <div>
      <h1> (ReasonReact.stringToElement "r/reasonml") </h1>
      <ul id="list"> (ReasonReact.arrayToElement itemsToRender) </ul>
    </div>
  }
};
