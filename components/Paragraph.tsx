import { Typography, makeStyles, createStyles } from '@material-ui/core';

const useStyles = makeStyles(theme =>
  createStyles({
    paragraph: {
      marginBottom: '16px',
    },
  }),
);

export const Paragraph = ({ children }) => {
  const classes = useStyles();
  return (
    <Typography variant="body1" component="p" className={classes.paragraph}>
      {children}
    </Typography>
  );
};
