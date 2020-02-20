import { Layout } from '../containers/Layout.gen';
import { Container, makeStyles, createStyles } from '@material-ui/core';
import { recommendations } from '../modules/Data.gen';
import { Paragraph } from '../components/Paragraph.gen';
import { SectionWithImage } from '../components/SectionWithImage.gen';

const useStyles = makeStyles(theme =>
  createStyles({
    anchor: {
      display: 'block',
      position: 'relative',
      top: -150,
      visibility: 'hidden',
    },
  }),
);

export default () => {
  const classes = useStyles();
  return (
    <Layout>
      <Container>
        {recommendations.map(recommendation => {
          const idName = recommendation.from.replace(/\s/g, '');

          return (
            <SectionWithImage
              src={recommendation.image}
              id={`${idName}-section`}
              title={recommendation.from}
              overline={recommendation.title}
              alt={recommendation.from}
            >
              <a className={classes.anchor} id={recommendation.from.replace(/\s/g, '')} />
              {recommendation.text.split(/\n/).map(p => (
                <Paragraph>{p}</Paragraph>
              ))}
            </SectionWithImage>
          );
        })}
      </Container>
    </Layout>
  );
};
