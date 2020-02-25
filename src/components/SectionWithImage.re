type classes = {clear: string};
let useStyles =
  Styles.(createStyles(Static({clear: make([clear(both)])})));

[@genType "SectionWithImage"]
[@react.component]
let make =
    (
      ~src,
      ~alt,
      ~children,
      ~title=?,
      ~overline=?,
      ~id,
      ~imgShadow=2,
      ~reverse=false,
      ~maxWidth=300,
    ) => {
  let classes = useStyles(.);
  let theme = Hooks.useTheme();
  let boxShadow = theme->MaterialUi_Theme.Theme.shadowsGet[imgShadow];
  let imgStyle =
    ReactDOMRe.Style.make(
      ~maxWidth=maxWidth->string_of_int ++ "px",
      ~float=reverse ? "right" : "left",
      ~boxShadow,
      ~margin=
        theme->MaterialUi_Theme.Theme.spacingGet(2)->string_of_int ++ "px",
      (),
    );
  <Section id>
    <img style=imgStyle src alt />
    {switch (title, overline) {
     | (Some(t), Some(o)) => <SectionHeader title=t overline=o />
     | _ => React.null
     }}
    children
    <div className={classes.clear} />
  </Section>;
};