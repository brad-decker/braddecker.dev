import { Typography, makeStyles, createStyles } from '@material-ui/core';
import { ReactNode } from 'react';

const useStyles = makeStyles(theme =>
  createStyles({
    paragraph: {
      marginBottom: '16px',
    },
  }),
);

interface ParagraphProps {
  children: ReactNode;
}

export const Paragraph = ({ children }: ParagraphProps) => {
  const classes = useStyles();
  return (
    <Typography variant="body1" component="p" className={classes.paragraph}>
      {children}
    </Typography>
  );
};
