let component = ReasonReact.statelessComponent "Title";

let x = Util.x;

let make ::label _children => {
  ...component,
  render: fun _self => <h1> (ReasonReact.stringToElement (label ^ string_of_int x)) </h1>
};