type target =
  | Window(Webapi.Dom.Window.t)
  | Node(Webapi.Dom.Node.t);

type options = {
  disableHysteresis: option(bool),
  target: option(target),
  threshold: option(int),
};

type trigger = [ | `active | `inactive];

[@bs.module "@material-ui/core"]
external make: options => bool = "useScrollTrigger";

let useScrollTrigger = (~disableHysteresis=?, ~target=?, ~threshold=?, ()) => {
  make({disableHysteresis, target, threshold}) ? `active : `inactive;
};