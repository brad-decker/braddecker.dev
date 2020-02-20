[%mui.withStyles
  "Paragraph"(theme =>
    {root: Styles.(make([marginBottom(theme->getSpacing(4))]))}
  )
];

[@genType "Paragraph"]
[@react.component]
let make = (~children) => {
  let classes = Paragraph.useStyles();
  MaterialUi.(
    <Typography
      variant=`Body1 component={`String("p")} className={classes.root}>
      children
    </Typography>
  );
};