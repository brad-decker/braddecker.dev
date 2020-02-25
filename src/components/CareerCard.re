type classes = {
  root: string,
  actions: string,
  details: string,
  cardMedia: string,
};

let useStyles =
  Styles.(
    createStyles(
      Static({
        root: make([borderRadius(px(20)), display(`flex)]),
        actions: make([justifyContent(flexEnd)]),
        details: make([display(`flex), flexDirection(column)]),
        cardMedia:
          make([
            minWidth(px(100)),
            maxWidth(px(180)),
            backgroundColor(white),
            backgroundSize(contain),
          ]),
      }),
    )
  );

[@react.component]
let make =
    (
      ~image=?,
      ~title,
      ~company,
      ~start,
      ~end_,
      ~description,
      ~link: option(string),
    ) => {
  let classes = useStyles(.);

  let companyName = company->Data.Company.to_string;

  MaterialUi.(
    <Grid item=true xs=V12 md=V6>
      <Card className={classes.root}>
        {switch (image) {
         | Some(i) => <CardMedia image=i className={classes.cardMedia} />
         | None => React.null
         }}
        <div className={classes.details}>
          <CardContent>
            <Typography variant=`Overline color=`Secondary>
              {j|$companyName, $start to $end_|j}->React.string
            </Typography>
            <Typography
              gutterBottom=true variant=`H5 component={`String("h3")}>
              title->React.string
            </Typography>
            <Paragraph> description->React.string </Paragraph>
          </CardContent>
          <CardActions className={classes.actions}>
            {link->Belt.Option.mapWithDefault(React.null, href =>
               <Button size=`Small color=`Secondary href>
                 "Visit Site"->React.string
               </Button>
             )}
            <Button size=`Small variant=`Contained color=`Primary>
              "Details"->React.string
            </Button>
          </CardActions>
        </div>
      </Card>
    </Grid>
  );
};