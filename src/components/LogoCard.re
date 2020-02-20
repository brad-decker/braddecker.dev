[%mui.withStyles
  "LogoCard"(theme =>
    {
      root:
        Styles.(
          make([
            selector(
              "& :hover",
              [
                unsafe(
                  "box-shadow",
                  theme->MaterialUi_Theme.Theme.shadowsGet[6],
                ),
                selector(
                  "& .MuiCardMedia-root",
                  [transform(scale(1.2, 1.2))],
                ),
              ],
            ),
          ])
        ),
      media:
        Styles.(
          make([
            height(zero),
            paddingTop(`percent(56.25)),
            backgroundPosition(`hv((`center, `percent(60.)))),
            transition(~duration=350, ~timingFunction=easeIn, "transform"),
            backgroundSize(contain),
            backgroundColor(white),
          ])
        ),
    }
  )
];

[@react.component]
let make = (~target="_blank", ~href, ~image) => {
  let classes = LogoCard.useStyles();
  MaterialUi.(
    <Card className={classes.root}>
      <Next.Link target href>
        <CardActionArea>
          <CardMedia image className={classes.media} />
        </CardActionArea>
      </Next.Link>
    </Card>
  );
};