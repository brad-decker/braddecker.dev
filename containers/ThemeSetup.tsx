import React from 'react';
import { ThemeProvider, createMuiTheme } from '@material-ui/core';
import { purple, teal, orange } from '@material-ui/core/colors';

const theme = createMuiTheme({
  palette: {
    type: 'dark',
    primary: teal,
    secondary: orange,
  },
});

export const ThemeSetup = ({ children }) => {
  return <ThemeProvider theme={theme}>{children}</ThemeProvider>;
};
