type postData = {
	id: string,
	title: string,
	url: string
};
type post = {
	data: postData
};
type responseData = {
	after: option bool,
	before: option bool,
	children: array post,
	modhash: string
};
type response = {
	data: responseData,
	kind: string
};

let parseRedditPostData json: postData => Json.Decode.{
	id: json |> field "id" string,
	title: json |> field "title" string,
	url: json |> field "url" string
};
let parseRedditPost json: post => Json.Decode.{
	data: json |> field "data" parseRedditPostData
};
let parseRedditPostArray json :array post => Json.Decode.(json |> array parseRedditPost);
let parseRedditData json: responseData => Json.Decode.{
	children: json |> field "children" parseRedditPostArray,
	modhash: json |> field "modhash" string,
	after: json |> optional (field "after" bool),
	before: json |> optional (field "before" bool)
};
let parseReddit json: response => Json.Decode.{
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
