let component = ReasonReact.statelessComponent "Router";

let make ::route ::redditPosts _children => {
  ...component,
  render: fun _state =>
    switch route {
    | "todos" => <TodoList />
    | "reddit" => <Reddit posts=redditPosts />
    | _ => <TodoList />
    }
};
