import React from 'react';
import { Layout } from '../containers/Layout';
import {
  makeStyles,
  createStyles,
  Container,
  GridList,
  GridListTile,
  GridListTileBar,
  Grid,
  List,
  ListItem,
  ListItemIcon,
  ListItemText,
  Typography,
} from '@material-ui/core';
import DoneOutline from '@material-ui/icons/DoneOutline';
import { Paragraph } from '../components/Paragraph';
import { SectionHeader } from '../components/SectionHeader';
import { achievements } from '../data/achivements';
import { CareerCard } from '../components/CareerCard';
import { jobHistory } from '../data/job-history';
import { Hero } from '../components/Hero';
import { recommendations } from '../data/recommendations';
import { RecommendationCard } from '../components/RecommendationCard';
import { languages, frameworks, softSkills } from '../data/skills';
import { SkillChip } from '../components/SkillChip';
import { Section } from '../components/Section';

const useStyles = makeStyles(theme =>
  createStyles({
    section: {
      marginBottom: '32px',
    },
    skillContainer: {
      display: 'flex',
      justifyContent: 'flex-start',
      flexWrap: 'wrap',
      marginBottom: theme.spacing(2),
      '& > *': {
        margin: theme.spacing(0.5),
      },
    },
  }),
);

const PORTFOLIO_DATA = [
  {
    title: 'Concierge Auctions',
    subtitle: 'Web application built with Node, React. Relay and GraphQL',
    image: 'images/concierge.png',
  },
  {
    title: 'HomeServices of America',
    subtitle: 'SaaS platform built with Node, React, Apollo and GraphQL',
    image: 'images/hsoa.png',
  },
  {
    title: 'Americlerkships',
    subtitle: 'Web application built with React, Salesforce and WordPress',
    image: 'images/acmedical.png',
  },
];

export default () => {
  const classes = useStyles();
  return (
    <Layout>
      <Hero image="images/home-background.jpg" lqip="images/blurry.jpg" />
      <Container>
        <Section title="Make an Impact" overline="Mission Statement" id="introduction">
          <Paragraph>
            Greetings, My name is Brad Decker, and I am a fullstack software engineer and experienced technical leader.
            I have experience implementing system architecture, user experiences, intuitive user features and leading
            teams of engineers in building products that scale. My goal is to find a new role where I can make an impact
            on the world.
          </Paragraph>
          <Paragraph>
            I have been working in the real estate industry for the last seven years. The mission throughout that
            journey has changed, but the underlying principle was to empower consumers to buy and sell real estate like
            never before. As a homeowner I know too well what it was like to be bounced between different companies and
            services. I had to maintain contact with a title services company, mortgage company, the brokerage, my agent
            and a few others along the way. I had to send sensitive documents through email, including my social
            security number. It was no surprise to me that in 2018 Americans lost nearly $150 million dollars to real
            estate scams and wire fraud. I had hoped to provide a seamless experience via a home buying and selling
            portal, but big change requires a massive investment of time, energy and money.
          </Paragraph>
          <Paragraph>
            In my next role I am looking for an environment that focuses on understanding the problem they are
            attempting to solve. As the lean methodology preaches, love your problem; not your solution. I hope to find
            a role that can make a broader impact on the role, either by creating software that empowers other engineers
            to more effectively help their customers, or by tackling challenges that we face as a civilization as we
            approach our next technical revolution.
          </Paragraph>
          <Paragraph>
            In my role as Director of Software Engineering at HomeServices of America, I never stopped being an
            individual contributor. Being hands on with the code is important to me. I firmly believe that it makes me a
            better leader when I can speak from an informed perspective about the technical challenges my team faces. It
            also is imperative in order to provide good solid feedback, mentorship and guidance to the engineers that I
            work with. I have received positive feedback from my teammates when I leave them constructive, informed and
            sometimes "good" guidance on their pull requests. I can only do that if I understand the codebase.
            Furthermore, writing code is why I am in this career path, and I cannot leave that behind.
          </Paragraph>
        </Section>
        <Section id="skills" title="Tools of the Trade" overline="Proficiencies">
          <Typography gutterBottom variant="subtitle2">
            Languages and Syntaxes
          </Typography>
          <div className={classes.skillContainer}>
            {languages.map(language => (
              <SkillChip {...language} />
            ))}
          </div>
          <Typography gutterBottom variant="subtitle2">
            Libraries and Frameworks
          </Typography>
          <div className={classes.skillContainer}>
            {frameworks.map(framework => (
              <SkillChip {...framework} />
            ))}
          </div>
          <Typography gutterBottom variant="subtitle2">
            Management and Soft Skills
          </Typography>
          <div className={classes.skillContainer}>
            {softSkills.map(skill => (
              <SkillChip {...skill} />
            ))}
          </div>
        </Section>
        <Section id="career" title="Experience" overline="Previous Employers">
          <Grid container spacing={2}>
            {jobHistory.map(job => (
              <CareerCard key={job.company} {...job} />
            ))}
          </Grid>
        </Section>
        <Section id="achievements" title="My Proudest Moments" overline="Achievements">
          <List>
            {achievements.map(achievement => (
              <ListItem key={achievement.primary}>
                <ListItemIcon>
                  <DoneOutline color="secondary" />
                </ListItemIcon>
                <ListItemText
                  primary={achievement.primary}
                  primaryTypographyProps={{ color: 'primary' }}
                  secondary={achievement.secondary}
                />
              </ListItem>
            ))}
          </List>
        </Section>
        <Section id="recommendations" title="What others say" overline="Recommendations">
          <Grid container spacing={2}>
            {recommendations.map(recommendation => (
              <RecommendationCard {...recommendation} />
            ))}
          </Grid>
        </Section>
        <Section id="portfolio" title="Case Studies and Demos" overline="Past Projects">
          <GridList cellHeight={280}>
            {PORTFOLIO_DATA.map(item => (
              <GridListTile key={item.title}>
                <img src={item.image} alt={item.title} />
                <GridListTileBar title={item.title} subtitle={item.subtitle} />
              </GridListTile>
            ))}
          </GridList>
        </Section>
      </Container>
    </Layout>
  );
};
