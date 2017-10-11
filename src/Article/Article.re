let component = ReasonReact.statelessComponent "Article";

let make ::title ::body _children => {
  ...component,
  render: fun _self => {
    let res = title ^ body;
    <div> <Title label=title /> <b> (ReasonReact.stringToElement res) </b> </div>
  }
};

let jsComponent =
  ReasonReact.wrapReasonForJs
    ::component (fun jsProps => make title::jsProps##title body::jsProps##body [||]);