[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "error"] `Error
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "textPrimary"] `TextPrimary
  | [@bs.as "textSecondary"] `TextSecondary
];

[@bs.deriving jsConverter]
type fontSize = [
  | [@bs.as "default"] `Default
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "small"] `Small
  | [@bs.as "large"] `Large
];

[@bs.obj]
external makePropsMui:
  (
    ~className: string=?,
    ~color: string=?,
    ~fontSize: string=?,
    ~nativeColor: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~titleAccess: string=?,
    ~viewBox: string=?,
    unit
  ) =>
  _;

let makeIconProps =
    (
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~fontSize: option(fontSize)=?,
      ~nativeColor: option(string)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      ~titleAccess: option(string)=?,
      ~viewBox: option(string)=?,
      (),
    ) =>
  makePropsMui(
    ~className?,
    ~color=?color->(Belt.Option.map(v => colorToJs(v))),
    ~fontSize=?fontSize->(Belt.Option.map(v => fontSizeToJs(v))),
    ~nativeColor?,
    ~style?,
    ~titleAccess?,
    ~viewBox?,
    (),
  );

module Menu = {
  module Outlined = {
    let makeProps = makeIconProps;
    [@bs.module "@material-ui/icons/MenuOutlined"]
    external make: React.component('a) = "default";
  };
};

module Done = {
  module Outlined = {
    let makeProps = makeIconProps;
    [@bs.module "@material-ui/icons/DoneOutlineOutlined"]
    external make: React.component('a) = "default";
  };
};

module Settings = {
  module Outlined = {
    let makeProps = makeIconProps;
    [@bs.module "@material-ui/icons/SettingsOutlined"]
    external make: React.component('a) = "default";
  };
};

module People = {
  module Outlined = {
    let makeProps = makeIconProps;
    [@bs.module "@material-ui/icons/PeopleOutlined"]
    external make: React.component('a) = "default";
  };
};

module MenuBook = {
  module Outlined = {
    let makeProps = makeIconProps;
    [@bs.module "@material-ui/icons/MenuBookOutlined"]
    external make: React.component('a) = "default";
  };
};