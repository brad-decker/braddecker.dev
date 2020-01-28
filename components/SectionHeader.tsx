import { Typography, createStyles, makeStyles } from '@material-ui/core';

const useStyles = makeStyles(theme =>
  createStyles({
    overline: {
      marginBottom: '-5px',
    },
  }),
);

export const SectionHeader = ({ title, overline }) => {
  const classes = useStyles();
  return (
    <>
      <Typography variant="overline" color="secondary" className={classes.overline}>
        {overline}
      </Typography>
      <Typography variant="h4" gutterBottom component="h2">
        {title}
      </Typography>
    </>
  );
};
