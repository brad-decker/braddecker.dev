import React, { ReactNode } from 'react';

import { AppBar } from '../components/AppBar';
import { CssBaseline } from '@material-ui/core';
import { ThemeSetup } from './ThemeSetup';
import { Footer } from '../components/Footer';

export const Layout = ({ children }: { children: ReactNode }) => (
  <ThemeSetup>
    <CssBaseline />
    <AppBar />
    {children}
    <Footer />
  </ThemeSetup>
);
