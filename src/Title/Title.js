// Generated by BUCKLESCRIPT VERSION 1.9.3, PLEASE EDIT WITH CARE
'use strict';

import * as Util        from "../Util.js";
import * as React       from "react";
import * as Pervasives  from "bs-platform/lib/es6/pervasives.js";
import * as ReasonReact from "reason-react/src/reasonReact.js";

var component = ReasonReact.statelessComponent("Title");

function make(label, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("h1", undefined, label + Pervasives.string_of_int(Util.x));
    });
  return newrecord;
}

var x = Util.x;

export {
  component ,
  x         ,
  make      ,
  
}
/* component Not a pure module */
