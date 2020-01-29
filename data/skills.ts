export interface Skill {
  name: string;
  logo?: string;
  iconClass?: string;
}

export const frameworks: Skill[] = [
  {
    name: 'React',
    logo: 'images/react.png',
    iconClass: 'fab fa-react',
  },
  {
    name: 'GraphQL',
    logo: '',
  },
  {
    name: 'Relay',
    logo: '',
  },
  {
    name: 'Apollo',
    logo: '',
  },
  {
    name: 'Reason React',
    logo: '',
  },
];

export const languages: Skill[] = [
  {
    name: 'JavaScript',
    logo: '',
    iconClass: 'fab fa-js',
  },
  {
    name: 'OCaml',
    logo: '',
  },
  {
    name: 'ReasonML',
    logo: '',
  },
  {
    name: 'PHP',
    logo: '',
    iconClass: 'fab fa-php',
  },
  {
    name: 'Node',
    logo: 'images/nodejslogo.png',
    iconClass: 'fab fa-node-js',
  },
  {
    name: 'Ruby',
    logo: '',
    iconClass: 'fas fa-gem',
  },
  {
    name: 'HTML',
    logo: '',
    iconClass: 'fab fa-html5',
  },
  {
    name: 'CSS',
    logo: '',
    iconClass: 'fab fa-css3',
  },
  {
    name: 'SASS',
    iconClass: 'fab fa-sass',
  },
];

export const softSkills: Skill[] = [
  {
    name: 'Leadership',
    logo: '',
  },
  {
    name: 'Mentoring',
    logo: '',
  },
  {
    name: 'Presentations',
    logo: '',
  },
];
