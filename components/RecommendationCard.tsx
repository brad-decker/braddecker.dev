import {
  Grid,
  Card,
  CardHeader,
  Avatar,
  CardContent,
  Collapse,
  CardActions,
  makeStyles,
  createStyles,
  IconButton,
  Typography,
  Link,
  Button,
} from '@material-ui/core';
import { Paragraph } from './Paragraph';
import { useState } from 'react';
import clsx from 'clsx';
import ExpandMoreIcon from '@material-ui/icons/ExpandMore';

const useStyles = makeStyles(theme =>
  createStyles({
    expand: {
      marginLeft: 'auto',
    },
  }),
);

export const RecommendationCard = ({ text, date, from, title, image, relationship, linkedin }) => {
  const classes = useStyles();
  const [isExpanded, setExpanded] = useState(false);
  const paragraphs = text.slice().split(/\n/);
  return (
    <Grid item xs={12} md={6} key={from}>
      <Card>
        <CardHeader
          avatar={<Avatar src={image} />}
          title={
            <Link href={linkedin} target="_blank">
              {from}, {title}
            </Link>
          }
          subheader={date}
        />
        <CardContent>
          <Paragraph>{paragraphs[0]}</Paragraph>
        </CardContent>
        <CardActions disableSpacing>
          <Button onClick={() => setExpanded(prev => !prev)} aria-expanded={isExpanded} className={classes.expand}>
            {isExpanded ? 'Hide Recommendation' : 'See Full Recommendation'}
          </Button>
        </CardActions>
        <Collapse in={isExpanded} timeout="auto" unmountOnExit>
          <CardContent>
            <Typography gutterBottom variant="subtitle1">
              Full Recommendation:
            </Typography>
            {paragraphs.map(p => (
              <Paragraph>{p}</Paragraph>
            ))}
          </CardContent>
        </Collapse>
      </Card>
    </Grid>
  );
};
