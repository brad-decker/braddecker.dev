/* TypeScript file generated from Section.re by genType. */
/* eslint-disable import/first */


import * as React from 'react';

const $$toRE484305802: { [key: string]: any } = {"primary": 58474434, "secondary": -499495052};

const $$toRE528368585: { [key: string]: any } = {"center": 98248149, "left": -944764921, "right": -379319332};

// tslint:disable-next-line:no-var-requires
const SectionBS = require('./Section.bs');

// tslint:disable-next-line:interface-over-type-literal
export type Props<overline,title> = {
  readonly children: React.ReactNode; 
  readonly className?: string; 
  readonly color?: 
    "primary"
  | "secondary"; 
  readonly id: string; 
  readonly overline?: overline; 
  readonly textAlign?: 
    "center"
  | "left"
  | "right"; 
  readonly title?: title
};

export const Section: React.ComponentType<{
  readonly children: React.ReactNode; 
  readonly className?: string; 
  readonly color?: 
    "primary"
  | "secondary"; 
  readonly id: string; 
  readonly overline?: any; 
  readonly textAlign?: 
    "center"
  | "left"
  | "right"; 
  readonly title?: any
}> = function Section_Section<overline,title>(Arg1: any) {
  const $props = {children:Arg1.children, className:Arg1.className, color:(Arg1.color == null ? undefined : $$toRE484305802[Arg1.color]), id:Arg1.id, overline:Arg1.overline, textAlign:(Arg1.textAlign == null ? undefined : $$toRE528368585[Arg1.textAlign]), title:Arg1.title};
  const result = React.createElement(SectionBS.make, $props);
  return result
};
