[%mui.withStyles
  "RecommendationCard"({
    root: Styles.(make([maxHeight(px(400))])),
    expand: Styles.(make([marginLeft(auto)])),
  })
];

let newline = [%bs.re "/\\n/g"];
let space = [%bs.re "/\\s/g"];
let onefiftychars = [%bs.re "/^(.{150}[^\s]*).*/"];

[@react.component]
let make = (~text, ~date, ~from, ~title, ~image, ~relationship, ~linkedin) => {
  let classes = RecommendationCard.useStyles();
  let paragraphs = text->Js.String2.splitByRe(newline);
  let firstParagraph =
    paragraphs[0]
    ->Belt.Option.mapWithDefault("", p => p)
    ->Js.String2.replaceByRe(onefiftychars, "$1");

  MaterialUi.(
    <Grid item=true xs=V12 sm=V4>
      <Card className={classes.root}>
        <CardHeader
          avatar={<Avatar src=image />}
          title={
            <Link href=linkedin target="_blank">
              {j|$from, $title|j}->React.string
            </Link>
          }
          subheader=date
        />
        <CardContent>
          <Paragraph> firstParagraph->React.string </Paragraph>
        </CardContent>
        <CardActions disableSpacing=true>
          <Next.Link href={from->Js.String2.replaceByRe(space, "")}>
            <Button color=`Secondary className={classes.expand}>
              "Read More"->React.string
            </Button>
          </Next.Link>
        </CardActions>
      </Card>
    </Grid>
  );
};