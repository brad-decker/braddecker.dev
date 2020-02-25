type classes = {
  container: string,
  shared: string,
  title: string,
};

let useStyles =
  Styles.(
    createStyles(
      Static({
        container:
          make([
            height(vh(100.)),
            marginBottom(px(32)),
            marginTop(px(-64)),
            position(relative),
            zIndex(-1),
            display(`flex),
            alignItems(center),
          ]),
        shared:
          make([
            backgroundPosition(center),
            backgroundSize(cover),
            backgroundRepeat(noRepeat),
            position(absolute),
            opacity(0.5),
            top(zero),
            bottom(zero),
            right(zero),
            left(zero),
          ]),
        title: make([height(px(120)), textAlign(center), zIndex(1)]),
      }),
    )
  );

type slideStatus = [ | `in_ | `out_];

let bool_of_slideStatus = slideStatus =>
  switch (slideStatus) {
  | `in_ => true
  | `out_ => false
  };
[@react.component]
let make = (~image, ~lqip) => {
  let classes = useStyles(.);
  let imageResult = Hooks.useLQIP(~mode=`css, ~full=image, ~placeholder=lqip);
  let imageStyle =
    switch (imageResult) {
    | StyleObject(v) => v
    | ImageSrc(_) => ReactDOMRe.Style.make()
    };
  let (slideStatus, setSlideStatus) = React.useState(() => `out_);
  let in_ = bool_of_slideStatus(slideStatus);
  let title = Hooks.useTitleLoop(~delay=2000, ~loopStarted=in_);
  React.useEffect0(() => {
    Js.Global.setTimeout(() => setSlideStatus(_ => `in_), 1500);
    None;
  });
  MaterialUi.(
    <div className={classes.container}>
      <Container className={classes.title}>
        <Typography variant=`H3 component={`String("h1")}>
          "Hello, I'm Brad."->React.string
        </Typography>
        <Slide in_ direction=`Right timeout={`Int(2000)}>
          <Typography variant=`H4 component={`String("h2")}>
            {j|I am a $title.|j}->React.string
          </Typography>
        </Slide>
      </Container>
      <div className={classes.shared} style=imageStyle />
    </div>
  );
};