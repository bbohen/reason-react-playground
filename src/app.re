type state = {redditPosts: array RedditData.post, route: string};

let component = ReasonReact.statefulComponent "App";

let make _children => {
  ...component,
  initialState: fun () => {redditPosts: [||], route: "/"},
  didMount: fun _state self => {
    let routeHandler route state _self => ReasonReact.Update {...state, route};
    let updateRedditPosts (response: RedditData.response) state _self =>
      ReasonReact.Update {...state, redditPosts: response.data.children};
    let director = DirectorRe.makeRouter {"/:wildcard": self.update routeHandler};
    DirectorRe.init director "/";
    ignore (RedditData.fetchRedditPosts (self.update updateRedditPosts));
    ReasonReact.NoUpdate
  },
  render: fun {redditPosts, route} _self =>
    <main> <Navigation route /> <section> <Router redditPosts route /> </section> </main>
};
