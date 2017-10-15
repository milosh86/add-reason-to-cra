type action =
  | Tick
  | BodyClick;

type state = {count: int};

let component = ReasonReact.reducerComponent "Article";

let handleClick _event self => {
  self.ReasonReact.reduce (fun _ => Tick) ();
  let countStr = string_of_int self.ReasonReact.state.count;
  Js.log ("clicked: " ^ countStr);
};

let getInc size => 2 * size;

let make ::title ::body _children => {
  ...component,
  initialState: fun () => {count: 0},
  reducer: fun action state =>
    switch action {
    | Tick => ReasonReact.Update {...state, count: state.count + getInc 1}
    | BodyClick => ReasonReact.UpdateWithSideEffects state (fun _self => Js.log "body clicked!")
    },
  render: fun self =>
    <div onClick=(self.handle handleClick)>
      <Title label=title />
      <b onClick=(self.reduce (fun _ev => BodyClick))> (ReasonReact.stringToElement body) </b>
    </div>
};

let jsComponent =
  ReasonReact.wrapReasonForJs
    ::component (fun jsProps => make title::jsProps##title body::jsProps##body [||]);
/* ReactDOMRe.renderToElementWithClassName (make title::"Hello!" body::"ovo je test" [||]) "index"; */