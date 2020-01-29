import React, { useEffect, useRef, useState } from 'react';
import clsx from 'clsx';
import { createStyles, makeStyles, Theme } from '@material-ui/core/styles';
import MUIAppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import Typography from '@material-ui/core/Typography';
import IconButton from '@material-ui/core/IconButton';
import MenuIcon from '@material-ui/icons/Menu';
import GitHubIcon from '@material-ui/icons/GitHub';
import LinkedInIcon from '@material-ui/icons/LinkedIn';
import { useScrollTrigger, Icon, Avatar, Slide } from '@material-ui/core';

const useStyles = makeStyles((theme: Theme) =>
  createStyles({
    root: {
      flexGrow: 1,
      transition: 'all 0.35s ease-out',
      willChange: 'background-color',
      // marginBottom: `-64px`,
      zIndex: 1,
    },
    transparent: {
      backgroundColor: 'rgba(0,0,0,0.15)',
    },
    menuButton: {
      marginRight: theme.spacing(2),
    },
    title: {
      flexGrow: 1,
      display: 'flex',
      alignItems: 'center',
    },
    avatar: {
      marginRight: 8,
    },
  }),
);

const titles = ['Director of Software Engineering', 'Lead Engineer', 'Web Developer', 'Architect'];

export const AppBar = () => {
  const classes = useStyles();
  const titleIncrement = useRef(0);
  const [title, setTitle] = useState(titles[titleIncrement.current]);

  const trigger = useScrollTrigger({
    disableHysteresis: true,
    threshold: 50,
  });

  const appBarClass = clsx({
    [classes.root]: true,
    [classes.transparent]: !trigger,
  });

  useEffect(() => {
    function changeTitle() {
      if (titleIncrement.current < titles.length - 1) {
        titleIncrement.current++;
      } else {
        titleIncrement.current = 0;
      }
      setTitle(titles[titleIncrement.current]);
    }
    const intervalId = setInterval(changeTitle, 800);
    return () => clearInterval(intervalId);
  }, []);

  return (
    <MUIAppBar position={trigger ? 'sticky' : 'static'} className={appBarClass} elevation={trigger ? 4 : 0}>
      <Toolbar>
        <IconButton edge="start" className={classes.menuButton} color="inherit" aria-label="menu">
          <MenuIcon />
        </IconButton>
        <div className={classes.title}>
          <Avatar
            component="a"
            href="https://www.linkedin.com/in/bhdecker/"
            target="_blank"
            className={classes.avatar}
            src="https://media-exp1.licdn.com/dms/image/C5603AQHBUqVSKzlFPQ/profile-displayphoto-shrink_200_200/0?e=1585785600&v=beta&t=Qv06qfyaTXFAd4Bd5pESsNMfy_Py4dyRq7AEaTIopU8"
          />
          <Slide in={trigger} direction="down">
            <Typography variant="h6" component="p">
              Brad Decker, {title}
            </Typography>
          </Slide>
        </div>

        <IconButton
          aria-label="view site source"
          aria-controls="menu-appbar"
          href="https://github.com/brad-decker/braddecker.dev"
          target="_blank"
        >
          <GitHubIcon />
        </IconButton>
        <IconButton
          aria-label="Stackoverflow"
          aria-controls="menu-appbar"
          href="https://stackoverflow.com/users/2642092/brad-decker"
          target="_blank"
        >
          <Icon className="fab fa-stack-overflow" />
        </IconButton>
      </Toolbar>
    </MUIAppBar>
  );
};
