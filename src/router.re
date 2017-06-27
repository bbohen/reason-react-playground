let component = ReasonReact.statelessComponent "Router";

let make ::route ::redditPosts _children => {
  ...component,
  render: fun _state _self =>
    switch route {
    | "todos" => <TodoList />
    | "reddit" => <Reddit posts=redditPosts />
    | _ => <TodoList />
    }
};
