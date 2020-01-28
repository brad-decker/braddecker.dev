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
  Card,
  CardHeader,
  Avatar,
  CardContent,
} from '@material-ui/core';
import DoneOutline from '@material-ui/icons/DoneOutline';
import { Paragraph } from '../components/Paragraph';
import { SectionHeader } from '../components/SectionHeader';
import { achievements } from '../data/achivements';
import { CareerCard } from '../components/CareerCard';
import { jobHistory } from '../data/job-history';
import { useLQIP } from '../hooks/useLQIP';
import { Hero } from '../components/Hero';
import { recommendations } from '../data/recommendations';
import { RecommendationCard } from '../components/RecommendationCard';

const useStyles = makeStyles(theme =>
  createStyles({
    portfolio: {},
    section: {
      marginBottom: '32px',
    },
    cardMedia: {
      height: 200,
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
        <section id="introduction" className={classes.section}>
          <SectionHeader title="Make an Impact" overline="Mission Statement" />
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
        </section>
        <section id="career" className={classes.section}>
          <SectionHeader title="Career History" overline="Previous Employers" />
          <Grid container spacing={2}>
            {jobHistory.map(job => (
              <CareerCard key={job.company} {...job} />
            ))}
          </Grid>
        </section>
        <section id="achievements" className={classes.section}>
          <SectionHeader title="My Proudest Moments" overline="Achievements" />
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
        </section>
        <section id="recommendations" className={classes.section}>
          <SectionHeader title="What others say" overline="Recommendations" />
          <Grid container spacing={2}>
            {recommendations.map(recommendation => (
              <RecommendationCard {...recommendation} />
            ))}
          </Grid>
        </section>
        <section id="portfolio">
          <SectionHeader title="Case Studies and Demos" overline="Past Projects" />
          <GridList className={classes.portfolio} cellHeight={280}>
            {PORTFOLIO_DATA.map(item => (
              <GridListTile key={item.title}>
                <img src={item.image} alt={item.title} />
                <GridListTileBar title={item.title} subtitle={item.subtitle} />
              </GridListTile>
            ))}
          </GridList>
        </section>
      </Container>
    </Layout>
  );
};
