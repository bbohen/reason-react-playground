type state = {
  redditPosts: array RedditData.post,
  route: string
};

let component = ReasonReact.statefulComponent "App";

let make _children => {
  ...component,
  initialState: fun () => {redditPosts: [||], route: "/"},
  didMount: fun {update} => {
    let routeHandler route {ReasonReact.state: state} => ReasonReact.Update {...state, route};
    let updateRedditPosts (response: RedditData.response) {ReasonReact.state: state} =>
      ReasonReact.Update {...state, redditPosts: response.data.children};
    let director = DirectorRe.makeRouter {"/:wildcard": update routeHandler};
    DirectorRe.init director "/";
    ignore (RedditData.fetchRedditPosts (update updateRedditPosts));
    ReasonReact.NoUpdate
  },
  render: fun self => {
    let {redditPosts, route} = self.state;
    <main> <Navigation route /> <section> <Router redditPosts route /> </section> </main>
  }
};
