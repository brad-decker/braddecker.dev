type classes = {
  header: string,
  avatar: string,
  grid: string,
  card: string,
};
let useStyles =
  Styles.(
    createStyles(
      WithTheme(
        theme =>
          {
            header:
              make([backgroundColor(theme->getFullPalette.primaryDark)]),
            avatar:
              make([backgroundColor(theme->getFullPalette.textPrimary)]),
            grid: make([selector("& > *", [flexGrow(1.)])]),
            card: make([height(`percent(100.))]),
          },
      ),
    )
  );

[@react.component]
let make = () => {
  let classes = useStyles(.);
  MaterialUi.(
    <Section id="roles">
      <Grid container=true spacing=V2 className={classes.grid}>
        <Grid item=true xs=V12 sm=V6 md=V4>
          <Card className={classes.card}>
            <CardHeader
              avatar={
                <Avatar className={classes.avatar}>
                  <MaterialIcons.Settings.Outlined />
                </Avatar>
              }
              className={classes.header}
              title={
                <Typography variant=`H5 component={`String("h2")}>
                  "FullStack Engineer"->React.string
                </Typography>
              }
            />
            <CardContent>
              <Typography
                variant=`Subtitle1 component={`String("p")} gutterBottom=true>
                "I apply my engineering skills across the stack to build products that empower people."
                ->React.string
              </Typography>
              <br />
              <Typography
                variant=`H6
                component={`String("p")}
                gutterBottom=true
                color=`Secondary>
                "Languages and Syntaxes"->React.string
              </Typography>
              <Paragraph>
                "Javascript, Node, Python, Ruby, PHP, OCaml, ReasonML, HTML, CSS, Sass"
                ->React.string
              </Paragraph>
              <Typography
                variant=`H6
                component={`String("p")}
                gutterBottom=true
                color=`Secondary>
                "Frameworks and Libraries"->React.string
              </Typography>
              <Paragraph>
                "React, GraphQL, Relay, Apollo, Next.js, Reason React, Material UI, Styled Components"
                ->React.string
              </Paragraph>
              <Typography
                variant=`H6
                component={`String("p")}
                gutterBottom=true
                color=`Secondary>
                "OSS Contributions"->React.string
              </Typography>
              <Paragraph>
                "Node, React, Relay, Moleculer, styled-components, Next.js, graphql-sequelize"
                ->React.string
              </Paragraph>
            </CardContent>
          </Card>
        </Grid>
        <Grid item=true xs=V12 sm=V6 md=V4>
          <Card className={classes.card}>
            <CardHeader
              className={classes.header}
              avatar={
                <Avatar className={classes.avatar}>
                  <MaterialIcons.People.Outlined />
                </Avatar>
              }
              title={
                <Typography variant=`H5 component={`String("h2")}>
                  "Technical Leader"->React.string
                </Typography>
              }
            />
            <CardContent>
              <Typography
                variant=`Subtitle1 component={`String("p")} gutterBottom=true>
                "I help act on product vision by building the team, principles and culture to design and implement
                scalable technology."
                ->React.string
              </Typography>
              <br />
              <Typography
                variant=`H6
                component={`String("p")}
                gutterBottom=true
                color=`Secondary>
                "Skills"->React.string
              </Typography>
              <Paragraph>
                "Leadership, Culture Building, Technical Writing, Speaking, Presenting, Recruiting, Driving Ownership and
                Alignment, Outcome Driven Development"
                ->React.string
              </Paragraph>
              <Typography
                variant=`H6
                component={`String("p")}
                gutterBottom=true
                color=`Secondary>
                "Outcomes"->React.string
              </Typography>
              <Paragraph>
                "I have assisted three companies by building the technology that matched their vision. One of those led
                to the acquisition of my team and the technology we built. I have built great, high engagement,
                engineering cultures that deliver results."
                ->React.string
              </Paragraph>
            </CardContent>
          </Card>
        </Grid>
        <Grid item=true xs=V12 sm=V6 md=V4>
          <Card className={classes.card}>
            <CardHeader
              avatar={
                <Avatar className={classes.avatar}>
                  <MaterialIcons.MenuBook.Outlined />
                </Avatar>
              }
              className={classes.header}
              title={
                <Typography variant=`H5 component={`String("h2")}>
                  "Mentor"->React.string
                </Typography>
              }
            />
            <CardContent>
              <Typography
                variant=`Subtitle1 component={`String("p")} gutterBottom=true>
                "A great product is nothing without a team of motivated engineers, dedicated to continuous learning, to
                power it."
                ->React.string
              </Typography>
              <br />
              <Typography
                variant=`H6
                component={`String("p")}
                gutterBottom=true
                color=`Secondary>
                "Mentorship topics"->React.string
              </Typography>
              <Paragraph>
                "Pragmatic programming, code quality, architectural principles, technical leadership, process &
                organization, problem solving, culture building"
                ->React.string
              </Paragraph>
              <Typography
                variant=`H6
                component={`String("p")}
                gutterBottom=true
                color=`Secondary>
                "Examples"->React.string
              </Typography>
              <Paragraph>
                "I am a ReasonML mentor on Exercism.io, have mentored over two dozen engineers throughout my career, have
                helped people reach new heights in their own careers."
                ->React.string
              </Paragraph>
            </CardContent>
          </Card>
        </Grid>
      </Grid>
    </Section>
  );
};