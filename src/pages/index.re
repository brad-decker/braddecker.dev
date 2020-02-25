type classes = {
  section: string,
  skillContainer: string,
  intro: string,
  paper: string,
};
let styles =
  Styles.(
    WithTheme(
      theme =>
        {
          section: make([marginBottom(px(32))]),
          skillContainer:
            make([
              display(`flex),
              justifyContent(flexStart),
              flexWrap(wrap),
              marginBottom(theme->getSpacing(2)),
              selector(
                "& > *",
                [margin(theme->getSpacingMultipler(`Float(0.5)))],
              ),
            ]),
          intro: make([textAlign(center)]),
          paper:
            make([
              backgroundColor(MaterialUi.Colors.Common.white->materialToHex),
              color(MaterialUi.Colors.Common.black->materialToHex),
              padding(theme->getSpacing(2)),
            ]),
        },
    )
  );

[@react.component]
let make = () => {
  MaterialUi.(
    <Layout>
      <Styles.WithStyle styles>
        ...{classes =>
          <>
            <Hero
              image="images/home-background.jpg"
              lqip="images/blurry.jpg"
            />
            <Container>
              <Section id="introduction" className={classes.intro}>
                <Typography
                  variant=`H4 component={`String("h2")} gutterBottom=true>
                  "About Me."->React.string
                </Typography>
                <Paragraph>
                  "I have been creating web applications, web sites and helping to build winning engineering teams for just
            over ten years. I find great enjoyment in building products that greatly impact the lives of their users. I
            have a natural tendency to learn things as deeply as I can, and to encourage others to be involved in
            discussions and voice their ideas. Only through diversity of thought can we build truly great, inclusive
            products. Build, measure and learn because the only thing that is constant is change."
                  ->React.string
                </Paragraph>
              </Section>
              <Roles />
              <Products />
              <Section
                id="career" title="Experience" overline="Previous Employers">
                <Grid container=true spacing=V2>
                  {Data.careerHistory->Belt.Array.map(
                     (
                       {image, title, company, start, end_, link, description},
                     ) =>
                     <CareerCard
                       key={company->Data.Company.to_string}
                       title
                       company
                       image
                       start
                       end_
                       link
                       description
                     />
                   )}
                </Grid>
              </Section>
              <Section
                id="achievements"
                title="My Proudest Moments"
                overline="Achievements">
                <List>
                  {Data.achievements->Belt.Array.map(({primary, secondary}) =>
                     <ListItem key=primary>
                       <ListItemIcon>
                         <MaterialIcons.Done.Outlined color=`Secondary />
                       </ListItemIcon>
                       <ListItemText
                         primary={primary->React.string}
                         secondary={secondary->React.string}
                       />
                     </ListItem>
                   )}
                </List>
              </Section>
              <Section
                id="recommendations"
                title="What others say"
                overline="Recommendations">
                <Grid container=true spacing=V2>
                  {Data.recommendations->Belt.Array.map(
                     (
                       {
                         from,
                         title,
                         relationship,
                         linkedin,
                         date,
                         image,
                         text,
                       },
                     ) =>
                     <RecommendationCard
                       key=from
                       from
                       title
                       relationship
                       linkedin
                       date={date->React.string}
                       image
                       text
                     />
                   )}
                </Grid>
              </Section>
              <Section
                id="portfolio"
                title="Case Studies and Demos"
                overline="Past Projects">
                <GridList cellHeight={`Int(280)}>
                  {Data.portfolio->Belt.Array.map(({title, image, subtitle}) =>
                     <GridListTile key=title>
                       <img src=image alt=title />
                       <GridListTileBar
                         title={title->React.string}
                         subtitle={subtitle->React.string}
                       />
                     </GridListTile>
                   )}
                </GridList>
              </Section>
            </Container>
          </>
        }
      </Styles.WithStyle>
    </Layout>
  );
};

let default = make;