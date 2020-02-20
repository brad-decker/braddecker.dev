[%mui.withStyles
  "Section"(theme => {
    let darkPrimary =
      Styles.(getPalette(~mode=`dark, ~color=`primary, ~theme));
    let darkSecondary =
      Styles.(getPalette(~mode=`dark, ~color=`secondary, ~theme));
    let fourUnits = Styles.(theme->getSpacing(4));
    {
      root: Styles.(make([marginBottom(fourUnits)])),
      primaryBackground: Styles.(make([backgroundColor(darkPrimary)])),
      secondaryBackground: Styles.(make([backgroundColor(darkSecondary)])),
      expandToFull:
        Styles.(
          make([
            marginLeft(fourUnits),
            marginRight(fourUnits),
            padding(fourUnits),
          ])
        ),
      alignLeft: Styles.(make([textAlign(`left)])),
      alignCenter: Styles.(make([textAlign(`center)])),
      alignRight: Styles.(make([textAlign(`right)])),
    };
  })
];

[@genType "Section"]
[@react.component]
let make =
    (
      ~title=?,
      ~overline=?,
      ~className=?,
      ~color=?,
      ~textAlign=?,
      ~id,
      ~children,
    ) => {
  let (trigger, setRef) = Hooks.useScrollPoint();
  let classes = Section.useStyles();

  let computedClassName =
    Cn.make([
      classes.root,
      className->Cn.unpack,
      Cn.mapSome(
        color,
        fun
        | `primary => classes.primaryBackground
        | `secondary => classes.secondaryBackground,
      ),
      classes.expandToFull->Cn.ifSome(color),
      Cn.mapSome(
        textAlign,
        fun
        | `left => classes.alignLeft
        | `center => classes.alignCenter
        | `right => classes.alignRight,
      ),
    ]);

  MaterialUi.(
    <section
      id
      className=computedClassName
      ref={ReactDOMRe.Ref.callbackDomRef(ref => setRef(_ => ref))}>
      <Slide direction=`Up in_=trigger timeout={`Int(1000)}>
        <div>
          {switch (title, overline) {
           | (Some(t), Some(o)) =>
             <SectionHeader
               title=t
               overline=o
               onSecondary={
                 switch (color) {
                 | Some(`secondary) => true
                 | _ => false
                 }
               }
             />
           | _ => React.null
           }}
          children
        </div>
      </Slide>
    </section>
  );
};