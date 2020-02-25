type classes = {root: string};
let useStyles =
  Styles.(
    createStyles(
      WithTheme(
        theme => {
          let oneFive = theme->getSpacingMultipler(`Float(1.5));
          let zeroFive = theme->getSpacingMultipler(`Float(0.5));
          {
            root:
              make([
                height(theme->getSpacing(6)),
                borderRadius(theme->getSpacing(2)),
                padding4(
                  ~top=oneFive,
                  ~bottom=oneFive,
                  ~right=oneFive,
                  ~left=zeroFive,
                ),
                unsafe(
                  "box-shadow",
                  theme->MaterialUi_Theme.Theme.shadowsGet[4],
                ),
                selector("& .fa-php", [width(em(1.2))]),
                selector("& .fa-gem", [width(em(1.2))]),
              ]),
          };
        },
      ),
    )
  );
[@react.component]
let make = (~name, ~iconClass=?, ~logo=?) => {
  let classes = useStyles(.);
  let color = `Primary;
  let label = name->React.string;
  let className = classes.root;

  let (icon, avatar) =
    switch (iconClass, logo) {
    | (Some(ic), _) => (Some(<MaterialUi.Icon className=ic />), None)
    | (_, Some(src)) => (None, Some(<MaterialUi.Avatar src alt=name />))
    | _ => (None, None)
    };
  <MaterialUi.Chip className label color ?icon ?avatar />;
};