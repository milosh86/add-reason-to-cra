let component = ReasonReact.statelessComponent "Title";

let make ::label _children => {
    ...component,
    render: fun _self => <h1> (ReasonReact.stringToElement label) </h1>
};
