[@genType "Layout"]
[@react.component]
let make = (~children) => {
  <ThemeSetup>
    <MaterialUi.CssBaseline />
    <Header />
    children
    <Footer />
  </ThemeSetup>;
};