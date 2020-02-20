import { Container, Grid, makeStyles, createStyles, Typography } from '@material-ui/core';
import { Paragraph } from '../components/Paragraph.gen';
import { Layout } from '../containers/Layout.gen';
import { Section } from '../components/Section.gen';
import { SectionWithImage } from '../components/SectionWithImage.gen';

const useClasses = makeStyles(theme =>
  createStyles({
    video: {
      maxWidth: '100%',
      height: '100%',
      width: '100%',
    },
    container: {
      marginTop: 32,
    },
    inlineImage: {
      float: 'left',
      margin: theme.spacing(2),
      width: 300,
    },
    videoContainer: {
      position: 'relative',
      borderRadius: 8,
      boxShadow: theme.shadows[2],
      overflow: 'hidden',
    },
    videoOverlay: {
      position: 'absolute',
      left: 0,
      top: 0,
      bottom: 0,
      right: 0,
      padding: 8,
      display: 'flex',
      alignItems: 'center',
      justifyContent: 'center',
      textAlign: 'center',
      backgroundColor: 'rgba(0, 0, 0, 0.3)',
    },
    responsiveVideoContainer: {
      position: 'relative',
      overflow: 'hidden',
      '&::before': {
        content: '""',
        display: 'block',
        paddingBottom: '56.25% !important',
      },
      '& > iframe': {
        position: 'absolute',
        top: 0,
        left: 0,
        width: '100%',
        height: '100%',
        border: 0,
      },
    },
  }),
);

export default () => {
  const classes = useClasses();
  return (
    <Layout>
      <Container className={classes.container}>
        <Section id="concierge-intro">
          <div className={classes.videoContainer}>
            <div className={classes.videoOverlay}>
              <div>
                <Typography variant="h4" component="span" color="secondary">
                  CASE STUDY
                </Typography>
                <Typography variant="h3" component="h1">
                  Concierge Auctions
                </Typography>
              </div>
            </div>
            <video
              className={classes.video}
              poster="https://s3.amazonaws.com/media.conciergeauctions.com/home_page/poster.jpg"
              loop
              autoPlay
            >
              <source src="https://s3.amazonaws.com/media.conciergeauctions.com/webm/home.webm" type="video/webm" />
              <source src="https://s3.amazonaws.com/media.conciergeauctions.com/webm/home.mp4" type="video/mp4" />
            </video>
          </div>
        </Section>
        <SectionWithImage
          id="concierge-about"
          title="Introduction to Concierge"
          alt="Concierge Auctions"
          overline="Project Description"
          src="images/concierge.png"
          maxWidth={450}
        >
          <Paragraph>
            Concierge Auctions is a luxury real estate company that was founded in 2004. The company uses an auction
            model to sell non-distressed luxury homes in a much tighter timeline than traditional sales models.
            Typically multi-million dollar homes can sit on the market for five or more years before eventually being
            sold. Concierge Auctions offers a much faster timeline by combining digital and print marketing to register
            bidders on properties before the date of the auction. This process typically takes thirty days, at the end
            of which if the seller is satisfied with the quantity of bidders the home goes to auction.
          </Paragraph>
          <Paragraph>
            The marketing team at Concierge is world class. They know that what attracts buyers to the homes on their
            marketplace is the lifestyle it can afford its new owners. The marketing team uses high resolution
            photography, and in house film and design team, and the highest quality media to reach their target
            audience. These teams work together to make sure there are enough leads coming in to convert into bidders
            (and future sellers).
          </Paragraph>
          <Paragraph>
            To bring all of the pieces together and to reach as broad of an audience as possible, Concierge Auctions had
            to establish a web presence. Their website started off as a landing page for their marketing efforts, to
            help sign up bidders and sellers. This is where my team and I came in. Our long term goal was clear: create
            an online marketplace to connect buyers and sellers of luxury real estate. I led the effort to define the
            technology stack, centered around JavaScript, Node and React. Together with the help of our product team, a
            team of just three engineers built the first version of the Concierge web application.
          </Paragraph>
        </SectionWithImage>
        <SectionWithImage
          id="ca-stack"
          title="On the bleeding edge"
          overline="Technology Stack"
          src="images/filter.gif"
          alt="Concierge filter system"
          imgShadow={0}
          maxWidth={450}
          reverse
        >
          <Paragraph>
            As I defined the core architecture of our new platform, I focused on speed for the end user. The most
            frequent feedback we received on the WordPress site was how slow it was. We heard this from our team as well
            as our customers. I had spent the previous year working on and off with Angular, and I really enjoyed it.
            However, as I was planning out Concierge's frontend application I came across React. At the time the shadow
            dom was a new concept, and the speed at which it could render large lists of elements was unparalleled.{' '}
          </Paragraph>
          <Paragraph>
            When I pitched React to my CTO, Jacob Cantele, I had to have a use case in mind for why the speed of
            rendering lots of components would matter. To the right, you'll see the Concierge Auctions upcoming
            properties page, which shows all the properties currently open for bids and those that are opening soon.
            Looking for homes to bid on is the primary function of the platform. Hence, as we talked through the pros
            and cons of switching to React (which was relatively new compared to Angular), this is the use case we had
            in mind.
          </Paragraph>
          <Paragraph>
            The backend of the application was destined to be built with Node. I had fallen in love with the language,
            and the idea of having FullStack javascript engineers that could carryout both sides of our development.
            Jacob and I knew that at some point in the future we would explore mobile applications, and so I made the
            decision to separate the API server and frontend application. Doing so allowed us to scale them
            independently and would enable our future mobile application to consume the same data as our web
            application.
          </Paragraph>
          <Grid container spacing={2} direction="row-reverse">
            <Grid item xs={12} sm={6} md={6}>
              <Paragraph>
                As I started to explore best practices for building a RESTful API, I ran across a talk from Dan Schafer
                and Jing Chen where they introduced the concept of GraphQL. I was so impacted by the pros of GraphQL
                that I had yet another proposal for changing the architecture plan for the new platform.
              </Paragraph>
              <Paragraph>
                Luckily we had not yet commenced building out our RESTful API, and the pivot to use GraphQL was easy to
                sell. The amount of maintenance required on a GraphQL API vs a RESTful API is much less, and easy to
                pitch to business minded leaders. The adoption of React, GraphQL and Relay (GraphQL's counterpart on the
                frontend) put us firmly on the bleeding edge of technology.
              </Paragraph>
            </Grid>
            <Grid item xs={12} sm={6} md={6} className={classes.responsiveVideoContainer}>
              <iframe
                src="https://www.youtube.com/embed/9sc8Pyc51uU"
                frameBorder="0"
                allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture"
                allowFullScreen
              ></iframe>
            </Grid>
          </Grid>
        </SectionWithImage>
      </Container>
    </Layout>
  );
};
