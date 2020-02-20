/* TypeScript file generated from Data.re by genType. */
/* eslint-disable import/first */


const $$toJS181414337: { [key: string]: any } = {"-988424995": "hsoa", "200615731": "concierge", "-119955486": "lyntonweb", "-385250836": "studiobee", "87097824": "renner", "1046616847": "freelance"};

// tslint:disable-next-line:no-var-requires
const DataBS = require('./Data.bs');

// tslint:disable-next-line:interface-over-type-literal
export type Company_t = 
    "hsoa"
  | "concierge"
  | "lyntonweb"
  | "studiobee"
  | "renner"
  | "freelance";

// tslint:disable-next-line:interface-over-type-literal
export type Recommendation_t = {
  readonly from: string; 
  readonly title: string; 
  readonly company: Company_t; 
  readonly relationship: string; 
  readonly linkedin: string; 
  readonly date: string; 
  readonly image: string; 
  readonly text: string
};

export const recommendations: Recommendation_t[] = DataBS.recommendations.map(function _element(ArrayItem: any) { return {from:ArrayItem.from, title:ArrayItem.title, company:$$toJS181414337[ArrayItem.company], relationship:ArrayItem.relationship, linkedin:ArrayItem.linkedin, date:ArrayItem.date, image:ArrayItem.image, text:ArrayItem.text}});
