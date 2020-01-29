import { makeStyles, createStyles, Typography, Container, Slide } from '@material-ui/core';
import { useLQIP } from '../hooks/useLQIP';
import { useState, useEffect } from 'react';
import { useTitleLoop } from '../hooks/useTitleLoop';

interface HeroProps {
  lqip: string;
  image: string;
}

const useStyles = makeStyles(theme =>
  createStyles({
    container: {
      height: '450px',
      marginBottom: '32px',
      marginTop: '-64px',
      position: 'relative',
      zIndex: -1,
    },
    shared: {
      backgroundPosition: 'center 60%',
      backgroundSize: 'cover',
      backgroundRepeat: 'no-repeat',
      position: 'absolute',
      opacity: '0.5',
      top: 0,
      left: 0,
      right: 0,
      bottom: 0,
    },
    hero: (props: HeroProps) => ({
      backgroundImage: `url(${props.image})`,
    }),
    heroLQIP: (props: HeroProps) => ({
      backgroundImage: `url(${props.lqip})`,
    }),
    title: {
      textAlign: 'center',
      top: 164,
      zIndex: 1,
      position: 'relative',
    },
  }),
);

export const Hero = ({ image, lqip }: HeroProps) => {
  const classes = useStyles({ image, lqip });
  const [_, loaded] = useLQIP({ placeholder: lqip, full: image });
  const [slideIn, setSlideIn] = useState(false);
  const title = useTitleLoop(slideIn, 2000);
  useEffect(() => {
    setTimeout(() => setSlideIn(true), 1500);
  }, []);
  return (
    <div className={classes.container}>
      <Container className={classes.title}>
        <Typography variant="h3" component="h1">
          Hello, my name is Brad Decker.
        </Typography>
        <Slide in={slideIn} direction="right" timeout={2000} mountOnEnter unmountOnExit>
          <Typography variant="h4" component="h2">
            I am a {title}.
          </Typography>
        </Slide>
      </Container>
      {!loaded && <div className={`${classes.heroLQIP} ${classes.shared}`} />}
      <div className={`${classes.hero} ${classes.shared}`} />
    </div>
  );
};
