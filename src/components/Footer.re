[%mui.withStyles
  "Footer"(theme =>
    {
      root:
        Styles.(
          make([
            padding2(~v=theme->getSpacing(2), ~h=theme->getSpacing(3)),
            marginTop(`auto),
            backgroundColor(MaterialUi.Colors.Grey.c800->materialToHex),
          ])
        ),
    }
  )
];

[@react.component]
let make = () => {
  let classes = Footer.useStyles();
  MaterialUi.(
    <footer className={classes.root}>
      <Container>
        <Typography variant=`Body2 color=`TextSecondary>
          {React.string({js|Copyright © |js})}
          <Link color=`Inherit href="/">
            {React.string("Brad Decker ")}
          </Link>
          {React.string(
             Js.Date.make()->Js.Date.getFullYear->Js.Float.toString ++ ".",
           )}
        </Typography>
      </Container>
    </footer>
  );
};