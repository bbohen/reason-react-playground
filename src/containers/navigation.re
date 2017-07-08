let component = ReasonReact.statelessComponent "Navigation";

let make ::route _children => {
  ...component,
  render: fun _self =>
    <nav>
      <div>
        <NavItem route="todos" isActive=(route === "todos") />
        (ReasonReact.stringToElement " | ")
        <NavItem route="reddit" isActive=(route === "reddit") />
      </div>
    </nav>
};
