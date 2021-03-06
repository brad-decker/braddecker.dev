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

type styleType('a) =
  | Static('a)
  | WithTheme(MaterialUi_Theme.t => 'a);

let createStyles = (styles: styleType('a)) => {
  switch (styles) {
  | Static(rules) => makeStyles(rules)
  | WithTheme(rules) => makeStylesWithTheme(rules)
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