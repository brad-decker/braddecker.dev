import { Typography, createStyles, makeStyles } from '@material-ui/core';

const useStyles = makeStyles(theme =>
  createStyles({
    overline: {
      marginBottom: '-5px',
    },
  }),
);

interface SectionHeaderProps {
  title: string;
  overline: string;
}

export const SectionHeader = ({ title, overline }: SectionHeaderProps) => {
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
