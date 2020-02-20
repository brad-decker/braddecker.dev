/* TypeScript file generated from SectionWithImage.re by genType. */
/* eslint-disable import/first */


import * as React from 'react';

// tslint:disable-next-line:no-var-requires
const SectionWithImageBS = require('./SectionWithImage.bs');

// tslint:disable-next-line:interface-over-type-literal
export type Props<overline,title> = {
  readonly alt: string; 
  readonly children: React.ReactNode; 
  readonly id: string; 
  readonly imgShadow?: number; 
  readonly maxWidth?: number; 
  readonly overline?: overline; 
  readonly reverse?: boolean; 
  readonly src: string; 
  readonly title?: title
};

export const SectionWithImage: React.ComponentType<{
  readonly alt: string; 
  readonly children: React.ReactNode; 
  readonly id: string; 
  readonly imgShadow?: number; 
  readonly maxWidth?: number; 
  readonly overline?: any; 
  readonly reverse?: boolean; 
  readonly src: string; 
  readonly title?: any
}> = SectionWithImageBS.make;
