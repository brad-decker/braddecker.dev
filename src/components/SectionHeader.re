type classes = {overline: string};
let useStyles =
  Styles.(createStyles(Static({overline: make([marginBottom(px(-5))])})));

[@react.component]
let make = (~onSecondary=false, ~title, ~overline) => {
  let classes = useStyles(.);

  MaterialUi.(
    <>
      <Typography
        variant=`Overline
        color={onSecondary ? `Inherit : `Secondary}
        className={classes.overline}>
        overline
      </Typography>
      <Typography variant=`H4 gutterBottom=true component={`String("h2")}>
        title
      </Typography>
    </>
  );
};