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
  CardHeader,
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
