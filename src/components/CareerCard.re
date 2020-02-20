/*
  -- Typescript version of component at time of refactor --
  import {
    Grid,
    Typography,
    Card,
    CardContent,
    CardActions,
    Button,
    makeStyles,
    createStyles,
    CardMedia,
  } from '@material-ui/core';
  import { Paragraph } from './Paragraph';

  const useStyles = makeStyles(theme =>
    createStyles({
      root: {
        borderRadius: 20,
        display: 'flex',
      },
      actions: {
        justifyContent: 'flex-end',
      },
      details: {
        display: 'flex',
        flexDirection: 'column',
      },
      cardMedia: {
        minWidth: 100,
        maxWidth: 180,
        backgroundColor: 'white',
        backgroundSize: 'contain',
      },
    }),
  );

  type CareerCardProps = {
    image?: string;
    title: string;
    company: string;
    start: string;
    end: string;
    description: string;
    link?: string;
  };

  export const CareerCard = ({ image, title, company, start, end, description, link }: CareerCardProps) => {
    const classes = useStyles();
    return (
      <Grid item xs={12} md={6}>
        <Card className={classes.root}>
          {image && <CardMedia image={image} title={company} className={classes.cardMedia} />}
          <div className={classes.details}>
            <CardContent>
              <Typography variant="overline" color="secondary">
                {company}, {start} to {end}
              </Typography>
              <Typography gutterBottom variant="h5" component="h3">
                {title}
              </Typography>
              <Paragraph>{description}</Paragraph>
            </CardContent>
            <CardActions className={classes.actions}>
              {link && (
                <Button size="small" color="secondary" href={link} target="_blank">
                  Visit Site
                </Button>
              )}
              <Button size="small" variant="contained" color="primary">
                Details
              </Button>
            </CardActions>
          </div>
        </Card>
      </Grid>
    );
  };

 */
[%mui.withStyles
  "CareerCard"({
    root: Styles.(make([borderRadius(px(20)), display(`flex)])),
    actions: Styles.(make([justifyContent(flexEnd)])),
    details: Styles.(make([display(`flex), flexDirection(column)])),
    cardMedia:
      Styles.(
        make([
          minWidth(px(100)),
          maxWidth(px(180)),
          backgroundColor(white),
          backgroundSize(contain),
        ])
      ),
  })
];

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
  let classes = CareerCard.useStyles();

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