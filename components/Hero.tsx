import { makeStyles, createStyles } from '@material-ui/core';
import { useLQIP } from '../hooks/useLQIP';

const useStyles = makeStyles(theme =>
  createStyles({
    container: {
      height: '450px',
      marginBottom: '32px',
      position: 'relative',
    },
    shared: {
      backgroundPosition: 'center 60%',
      backgroundSize: 'cover',
      backgroundRepeat: 'no-repeat',
      position: 'absolute',
      top: 0,
      left: 0,
      right: 0,
      bottom: 0,
    },
    hero: (props: { image: string; lqip: string }) => ({
      backgroundImage: `url(${props.image})`,
      zIndex: -1,
    }),
    heroLQIP: (props: { image: string; lqip: string }) => ({
      backgroundImage: `url(${props.lqip})`,
      zIndex: -1,
    }),
  }),
);

export const Hero = ({ image, lqip }) => {
  const classes = useStyles({ image, lqip });
  const [_, loaded] = useLQIP({ placeholder: lqip, full: image });
  return (
    <div className={classes.container}>
      {!loaded && <div className={`${classes.heroLQIP} ${classes.shared}`} />}
      <div className={`${classes.hero} ${classes.shared}`} />
    </div>
  );
};
