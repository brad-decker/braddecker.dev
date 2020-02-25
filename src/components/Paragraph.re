type classes = {root: string};

let useStyles =
  Styles.(
    createStyles(
      WithTheme(
        theme => {root: make([marginBottom(theme->getSpacing(4))])},
      ),
    )
  );

[@genType "Paragraph"]
[@react.component]
let make = (~children) => {
  let classes = useStyles(.);
  MaterialUi.(
    <Typography
      variant=`Body1 component={`String("p")} className={classes.root}>
      children
    </Typography>
  );
};