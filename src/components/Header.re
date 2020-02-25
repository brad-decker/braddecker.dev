type classes = {
  root: string,
  transparent: string,
  menuButton: string,
  title: string,
  avatar: string,
};

let useStyles =
  Styles.(
    makeStylesWithTheme(theme =>
      {
        root:
          make([
            flexGrow(1.),
            zIndex(1),
            unsafe("will-change", "background-color"),
            unsafe("transition", "all 0.35s ease-out"),
          ]),
        transparent: make([backgroundColor(rgba(0, 0, 0, 0.15))]),
        menuButton: make([marginRight(theme->getSpacing(2))]),
        title: make([flexGrow(1.), display(`flex), alignItems(`center)]),
        avatar: make([marginRight(theme->getSpacing(2))]),
      }
    )
  );

[@react.component]
let make = () => {
  let classes = useStyles(.);

  let trigger =
    Hooks.useScrollTrigger(~disableHysteresis=true, ~threshold=50, ());
  Js.Console.log(classes);

  let className =
    Cn.make([
      classes.root,
      Cn.unpack(
        switch (trigger) {
        | `active => None
        | `inactive => Some(classes.transparent)
        },
      ),
    ]);

  let (position, elevation, in_) =
    switch (trigger) {
    | `active => (`Sticky, `Int(4), true)
    | `inactive => (`Static, `Int(0), false)
    };

  MaterialUi.(
    <AppBar className position elevation>
      <Toolbar>
        <IconButton edge=`Start className={classes.menuButton} color=`Inherit>
          <MaterialIcons.Menu.Outlined />
        </IconButton>
        <div className={classes.title}>
          <a href="https://linkedin.com" target="_blank">
            <Avatar
              className={classes.avatar}
              src="https://media-exp1.licdn.com/dms/image/C4E03AQEhd18AfGfBHQ/profile-displayphoto-shrink_200_200/0?e=1586995200&v=beta&t=067_9g6ZJ3rCOoxcW6oLuYohdCy4hxyhS0fjeRlkMyY"
            />
          </a>
          <Slide in_ direction=`Down>
            <Typography variant=`H6 component={`String("p")}>
              "Brad Decker"->React.string
            </Typography>
          </Slide>
        </div>
        <IconButtonCopy
          href="https://github.com/brad-decker/braddecker.dev" target="_blank">
          <Icon className="fab fa-github-alt" />
        </IconButtonCopy>
        <IconButtonCopy
          href="https://stackoverflow.com/users/2642092/brad-decker"
          target="_blank">
          <Icon className="fab fa-stack-overflow" />
        </IconButtonCopy>
      </Toolbar>
    </AppBar>
  );
};