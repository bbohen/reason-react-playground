let component = ReasonReact.statelessComponent "Reddit";

let make ::posts _children => {
  ...component,
  render: fun _self => {
    let itemsToRender = posts |> Array.map (fun postItem => <RedditPost post=postItem />);
    <div>
      <h1> (ReasonReact.stringToElement "r/reasonml") </h1>
      <ul id="list" className="reddit"> (ReasonReact.arrayToElement itemsToRender) </ul>
    </div>
  }
};
