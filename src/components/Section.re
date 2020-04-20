type classes = {
  root: string,
  primaryBackground: string,
  secondaryBackground: string,
  expandToFull: string,
  alignLeft: string,
  alignCenter: string,
  alignRight: string,
};

let useStyles =
  Styles.(
    createStyles(
      WithTheme(
        theme => {
          let fullPalette = theme->getFullPalette;
          let fourUnits = theme->getSpacing(4);
          {
            root: make([marginBottom(fourUnits)]),
            primaryBackground:
              make([backgroundColor(fullPalette.primaryDark)]),
            secondaryBackground:
              make([backgroundColor(fullPalette.secondaryDark)]),
            expandToFull:
              make([
                marginLeft(fourUnits),
                marginRight(fourUnits),
                padding(fourUnits),
              ]),
            alignLeft: make([textAlign(`left)]),
            alignCenter: make([textAlign(`center)]),
            alignRight: make([textAlign(`right)]),
          };
        },
      ),
    )
  );

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
  let classes = useStyles(.);

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