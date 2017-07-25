let component = ReasonReact.statelessComponent "RedditPost";

/* let make (post:: RedditData.postData) _children => { */
let make post::(post: RedditData.post) _children => {
  ...component,
  render: fun _self =>
    <li>
      <div>
        <a href=post.data.url target="_blank">
          <img src=post.data.thumbnail />
          <div>
            <span> (ReasonReact.stringToElement post.data.title) </span>
            <span> (ReasonReact.stringToElement ("Posted By: " ^ post.data.author)) </span>
          </div>
        </a>
      </div>
      <div>
        <a href=("https://www.reddit.com" ^ post.data.permalink) target="_blank">
          <span>
            (ReasonReact.stringToElement (string_of_int post.data.upvotes ^ " upvotes "))
            (ReasonReact.stringToElement (string_of_int post.data.downvotes ^ " downvotes "))
            (ReasonReact.stringToElement (string_of_int post.data.comment_count ^ " comments"))
          </span>
        </a>
      </div>
    </li>
};
