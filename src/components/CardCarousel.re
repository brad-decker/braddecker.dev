type classes = {
  root: string,
  item: string,
};

let useStyles =
  Styles.(
    createStyles(
      Static({
        root:
          make([
            maxWidth(`percent(100.)),
            unsafe("-webkit-overflow-scrolling", "touch"),
            overflowX(auto),
            selector("&::-webkit-scrollbar", [display(none)]),
          ]),

        item: make([flex3(~grow=0., ~shrink=0., ~basis=auto)]),
      }),
    )
  );
[@react.component]
let make = (~children) => {
  let classes = useStyles(.);
  MaterialUi.(
    <Grid container=true spacing=V2 wrap=`Nowrap className={classes.root}>
      {children->Belt.Array.map(child => {
         <Grid item=true xs=V12 sm=V4 className={classes.item}> child </Grid>
       })}
    </Grid>
  );
};