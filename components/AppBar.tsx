import React from 'react';
import clsx from 'clsx';
import { createStyles, makeStyles, Theme } from '@material-ui/core/styles';
import MUIAppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import Typography from '@material-ui/core/Typography';
import IconButton from '@material-ui/core/IconButton';
import MenuIcon from '@material-ui/icons/Menu';
import { useScrollTrigger } from '@material-ui/core';

const useStyles = makeStyles((theme: Theme) =>
  createStyles({
    root: {
      flexGrow: 1,
      transition: 'all 0.25s ease-out',
      willChange: 'background-color',
      marginBottom: `-64px`,
    },
    transparent: {
      backgroundColor: 'rgba(0,0,0,0.15)',
    },
    menuButton: {
      marginRight: theme.spacing(2),
    },
    title: {
      flexGrow: 1,
    },
  }),
);

export const AppBar = () => {
  const classes = useStyles();

  const trigger = useScrollTrigger({
    disableHysteresis: true,
    threshold: 50,
  });

  const appBarClass = clsx({
    [classes.root]: true,
    [classes.transparent]: !trigger,
  });

  return (
    <MUIAppBar position={trigger ? 'sticky' : 'static'} className={appBarClass} elevation={trigger ? 4 : 0}>
      <Toolbar>
        <IconButton edge="start" className={classes.menuButton} color="inherit" aria-label="menu">
          <MenuIcon />
        </IconButton>
        <Typography variant="h6" className={classes.title}>
          Brad Decker
        </Typography>
      </Toolbar>
    </MUIAppBar>
  );
};
