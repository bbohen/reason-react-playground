let parseRedditPostData json: RedditData.postData => Json.Decode.{
	id: json |> field "id" string,
	title: json |> field "title" string
};
let parseRedditPost json: RedditData.post => Json.Decode.{
	data: json |> field "data" parseRedditPostData
};
let parseRedditPostArray json :array RedditData.post => Json.Decode.(json |> array parseRedditPost);
let parseRedditData json: RedditData.responseData => Json.Decode.{
	children: json |> field "children" parseRedditPostArray,
	modhash: json |> field "modhash" string,
	after: json |> optional (field "after" bool),
	before: json |> optional (field "before" bool)
};
let parseReddit json: RedditData.response => Json.Decode.{
	data: json |> field "data" parseRedditData,
	kind: json |> field "kind" string
};
let fetchRedditPosts callback =>
	Js.Promise.(
		Bs_fetch.fetch "https://www.reddit.com/r/reasonml.json" |> then_ Bs_fetch.Response.text |>
		then_ (
			fun text =>
				Js.Json.parseExn text |> parseReddit |> (
					fun redditData => {
						callback redditData;
						resolve None;
					}
				)
		)
	);

/*component*/
type state = {
	redditPosts: array RedditData.post,
	route: string
};

let component = ReasonReact.statefulComponent "App";
let make _children => {
	...component,
	initialState: fun () => {
		redditPosts: [||],
		route: "/"
	},
	didMount: fun _state self => {
		let routeHandler route state _self => ReasonReact.Update {
			...state,
			route: route
		};
		let updateRedditPosts (response:RedditData.response) state _self =>
			ReasonReact.Update {
				...state,
				redditPosts: response.data.children
			};
		let director = DirectorRe.makeRouter {
			"/:wildcard": self.update routeHandler
		};
		DirectorRe.init director "/";
		fetchRedditPosts (self.update updateRedditPosts);
		ReasonReact.NoUpdate;
	},
	render: fun {redditPosts, route} _self =>
		<main>
			<Navigation route={route} />
			<section>
				<Router
					redditPosts={redditPosts}
					route={route}
				/>
			</section>
		</main>
};
