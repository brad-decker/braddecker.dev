let theme =
  MaterialUi.Theme.create(
    MaterialUi.ThemeOptions.(
      make(
        ~palette=
          PaletteOptions.make(
            ~type_="dark",
            ~primary=Primary.make(~main=MaterialUi.Colors.Teal.c400, ()),
            ~secondary=
              Secondary.make(~main=MaterialUi.Colors.Orange.c400, ()),
            (),
          ),
        (),
      )
    ),
  );

[@react.component]
let make = (~children) =>
  <MaterialUi.ThemeProvider theme> children </MaterialUi.ThemeProvider>;