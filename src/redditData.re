type postData = {
	id: string,
	title: string
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
