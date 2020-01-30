import { createStyles, makeStyles, Slide } from '@material-ui/core';
import { ReactNode } from 'react';
import { SectionHeader } from './SectionHeader';
import { useScrollPoint } from '../hooks/useScrollPoint';

interface SectionProps {
  title: string;
  overline: string;
  children: ReactNode;
  id: string;
}

const useStyles = makeStyles(theme =>
  createStyles({
    root: {
      marginBottom: theme.spacing(4),
    },
  }),
);

export const Section = ({ title, id, children, overline }: SectionProps) => {
  const classes = useStyles();
  const [trigger, setRef] = useScrollPoint({ once: true });
  return (
    <section className={classes.root} id={id} ref={setRef}>
      <Slide direction="up" in={trigger} timeout={1000}>
        <div>
          <SectionHeader title={title} overline={overline} />
          {children}
        </div>
      </Slide>
    </section>
  );
};
