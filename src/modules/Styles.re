include Css;
external convertJsonToStyles: Js.Json.t => ReactDOMRe.Style.t = "%identity";
external convertJsonToString: Js.Json.t => string = "%identity";
[@bs.module "@material-ui/core/styles"]
external makeStyles: 'a => (. unit) => 'a = "makeStyles";
[@bs.module "@material-ui/core/styles"]
external makeStylesWithTheme: (MaterialUi_Theme.t => 'a) => (. unit) => 'a =
  "makeStyles";

let make = (styles: list(Css.rule)) =>
  styles->Css.toJson->convertJsonToString;

let addPx = i => i->string_of_int ++ "px";

let getSpacing = (theme, input) => {
  MaterialUi.Theme.(px(theme->Theme.spacingGet(input)));
};

let roundf = x => snd(modf(x +. copysign(0.5, x)));

let getSpacingMultipler = (theme, input) => {
  switch (input) {
  | `Int(i) => theme->getSpacing(i)
  | `Float(i) =>
    px(
      (i *. theme->MaterialUi_Theme.Theme.spacingGet(1)->float_of_int)
      ->roundf
      ->int_of_float,
    )
  };
};

type mode = [ | `dark | `light];
type color = [ | `primary | `secondary];

let materialToHex = str => hex(str->Js.String2.replace("#", ""));

let getPalette = (~mode=?, ~color, ~theme) => {
  let getMethod =
    switch (mode) {
    | Some(`dark) => MaterialUi.Theme.PaletteColor.darkGet
    | Some(`light) => MaterialUi.Theme.PaletteColor.lightGet
    | None => MaterialUi.Theme.PaletteColor.mainGet
    };

  let colorMethod =
    switch (color) {
    | `primary => MaterialUi.Theme.Palette.primaryGet
    | `secondary => MaterialUi.Theme.Palette.secondaryGet
    };
  theme
  ->MaterialUi.Theme.Theme.paletteGet
  ->colorMethod
  ->getMethod
  ->materialToHex;
};

let getTextPalette = (~variation, ~theme) => {
  let variationMethod =
    switch (variation) {
    | `secondary => MaterialUi.Theme.TypeText.secondaryGet
    | `primary => MaterialUi.Theme.TypeText.primaryGet
    | `hint => MaterialUi.Theme.TypeText.hintGet
    | `disabled => MaterialUi.Theme.TypeText.disabledGet
    };
  theme
  ->MaterialUi.Theme.Theme.paletteGet
  ->MaterialUi.Theme.Palette.textGet
  ->variationMethod
  ->materialToHex;
};

[@unboxed]
type rules =
  | Rules('a): rules;

type t =
  | Static(rules): t
  | WithTheme(MaterialUi_Theme.t => rules): t;

let createStyles = (styles: t) => {
  switch (styles) {
  | Static(rules) => makeStyles(rules)
  | WithTheme(rules) => makeStylesWithTheme(rules)
  };
};

type palette = {
  primaryDark: Types.Color.t,
  primaryMain: Css.Types.Color.t,
  primaryLight: Types.Color.t,
  secondaryDark: Types.Color.t,
  secondaryMain: Types.Color.t,
  secondaryLight: Types.Color.t,
  textPrimary: Types.Color.t,
  textSecondary: Types.Color.t,
  textHint: Types.Color.t,
  textDisabled: Types.Color.t,
};

let getFullPalette = theme => {
  {
    primaryDark: getPalette(~mode=`dark, ~color=`primary, ~theme),
    primaryMain: getPalette(~mode=?None, ~color=`primary, ~theme),
    primaryLight: getPalette(~mode=`light, ~color=`primary, ~theme),
    secondaryDark: getPalette(~mode=`dark, ~color=`secondary, ~theme),
    secondaryMain: getPalette(~mode=?None, ~color=`secondary, ~theme),
    secondaryLight: getPalette(~mode=`light, ~color=`secondary, ~theme),
    textPrimary: getTextPalette(~variation=`primary, ~theme),
    textSecondary: getTextPalette(~variation=`secondary, ~theme),
    textDisabled: getTextPalette(~variation=`disabled, ~theme),
    textHint: getTextPalette(~variation=`hint, ~theme),
  };
};

module WithStyle = {
  [@react.component]
  let make = (~children, ~styles) => {
    let hook = createStyles(styles);
    let classes = hook(.);
    children(classes);
  };
};