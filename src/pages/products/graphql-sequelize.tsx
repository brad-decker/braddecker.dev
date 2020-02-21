import { Layout } from '../../containers/Layout.gen';
import { Paper, Container, Card, makeStyles, createStyles, Typography, Link } from '@material-ui/core';
import { Section } from '../../components/Section.gen';
import { Paragraph } from '../../components/Paragraph.gen';

const useStyles = makeStyles(theme =>
  createStyles({
    hero: {
      position: 'relative',
      backgroundColor: '#fff',
      textAlign: 'center',
      '& img': {
        // minWidth: '100%',
        filter: 'blur(10px) grayscale(50%)',
      },
      marginBottom: theme.spacing(4),
    },
    title: {
      position: 'absolute',
      display: 'flex',
      alignItems: 'center',
      justifyContent: 'center',
      top: 0,
      left: 0,
      right: 0,
      bottom: 0,
      textAlign: 'center',
      '& > div': {
        backgroundColor: 'rgba(0, 0, 0, 0.35)',
        width: '100%',
        padding: 10,
      },
    },
  }),
);

export default () => {
  const classes = useStyles();
  return (
    <Layout>
      <Container>
        <Card elevation={4} className={classes.hero}>
          <img src="/images/graphql.png" alt="GraphQL Sequelize Logo" />
          <div className={classes.title}>
            <div>
              <Typography color="secondary" variant="h3" component="span">
                Contribution Description
              </Typography>
              <br />
              <Typography variant="h1">GraphQL Sequelize</Typography>
            </div>
          </div>
        </Card>
        <Section id="intro" title="What is GraphQL-Sequelize?" overline="Product Description">
          <Paragraph>
            Sequelize is a popular ORM for node.js that provides a single API for defining models that interact with a
            variety of SQL server implementations. It has 21k stars on GitHub and is one of the most widely used ORMs in
            the space. We made the decision to use Sequelize at Concierge Auctions early on, as it reminded me of my
            experience using Ruby on Rails' active record.
          </Paragraph>
          <Paragraph>
            GraphQL-sequelize is a library that consumes your Sequelize schema and creates a GraphQL server based on
            your data. We created our GraphQL server at Concierge Auctions before you could define your schema with
            GraphQL string syntax. We opted to use GraphQL-sequelize to help us bootstrap our GraphQL API and to
            leverage the small but active GraphQL open source community.
          </Paragraph>
        </Section>
        <Section id="my-contribution" title="How did I make it better?" overline="My Contributions">
          <Paragraph>
            GraphQL actually has two specs published by Facebook. The first and most well referenced is the base GraphQL
            spec that lays out how a GraphQL server should respond to requests and how the schema works. There is a
            second more specific spec that is used only by Relay. Relay is Facebook's client side library for
            interacting with GraphQL APIs.
          </Paragraph>
          <Paragraph>
            One way that Relay differs from Apollo is that Relay attempts to track what it knows about nodes in the
            graph irrelevant to the query that fetched them. If Relay finds that you are requesting additional data for
            a node it already knows, it will only fetch the new fields. This is done by implementing a "Node" resolver
            in the GraphQL server. This resolver determines the type of the node based on it's ID.
          </Paragraph>
          <Paragraph>
            The Relay spec for GraphQL stipulates that the ID of a node must include a unique identifer for the node, as
            well as the type of node. GraphQl tools includes two utilities 'fromGobalId' and 'toGlobalId' that create a
            reversible hash of the unique identifier and the Node type. This, along with the Node resolver mentioned
            above are crucial elements required on the server side to enable Relay to work with the server{' '}
          </Paragraph>
          <Paragraph>
            The other piece of the Relay spec that is not enforced by the main GraphQL spec is the concept of
            connections. GraphQL is based on graph theory, Nodes exist independently from one another and are only
            associated via connections. A connection from a User to another User node might be called 'friends'. In a
            GraphQL schema that implements the connection spec you can collect all of those connections and count the
            number of nodes without actually fetching the individual nodes' data.
          </Paragraph>
          <Paragraph>
            When we adopted GraphQL sequelize it performed a query analysis and programmatically built a single query to
            resolve all the necessary data. The way that it did this is crawl the query tree and build a SQL statement,
            analyzing each type of leaf in the AST to determine what to add to the statement. Connections are a type of
            leaf in the AST and unfortunately GraphQL sequelize did not yet support Relay. So I had to{' '}
            <Link href="https://github.com/mickhansen/graphql-sequelize/pull/18">add support for connections</Link> to
            the query builder.
          </Paragraph>
          <Paragraph>
            As part of the same pull request I added an interface for making creation of the Node resolver easier. It
            provides some simple helpers to streamline the process of creating a global id field, and to hook it up to
            the corresponding Node resolver.
          </Paragraph>
        </Section>
      </Container>
    </Layout>
  );
};
