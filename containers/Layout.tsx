import React from 'react';

import { AppBar } from '../components/AppBar';
import { CssBaseline } from '@material-ui/core';
import { ThemeSetup } from './ThemeSetup';
import { Footer } from '../components/Footer';

export const Layout = ({ children }) => (
  <ThemeSetup>
    <CssBaseline />
    <AppBar />
    {children}
    <Footer />
  </ThemeSetup>
);
