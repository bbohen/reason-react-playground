let component = ReasonReact.statelessComponent "Reddit";

let make ::posts _children => {
  ...component,
  render: fun _self => {
    let itemsToRender =
      posts |>
      Array.map (
        fun (postItem: RedditData.post) =>
          <li key=postItem.data.id>
            <div>
              <a href=postItem.data.url target="_blank">
                <img src=postItem.data.thumbnail />
                <div>
                  <span> (ReasonReact.stringToElement postItem.data.title) </span>
                  <span>
                    (ReasonReact.stringToElement ("Posted By: " ^ postItem.data.author))
                  </span>
                </div>
              </a>
            </div>
            <div>
              <a href=("https://www.reddit.com" ^ postItem.data.permalink) target="_blank">
                <span>
                  (ReasonReact.stringToElement (string_of_int postItem.data.upvotes ^ " upvotes "))
                  (
                    ReasonReact.stringToElement (
                      string_of_int postItem.data.downvotes ^ " downvotes "
                    )
                  )
                  (
                    ReasonReact.stringToElement (
                      string_of_int postItem.data.comment_count ^ " comments"
                    )
                  )
                </span>
              </a>
            </div>
          </li>
      );
    <div>
      <h1> (ReasonReact.stringToElement "r/reasonml") </h1>
      <ul id="list" className="reddit"> (ReasonReact.arrayToElement itemsToRender) </ul>
    </div>
  }
};
