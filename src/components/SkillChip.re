[%mui.withStyles
  "SkillChip"(theme => {
    let oneFive = theme->Styles.getSpacingMultipler(`Float(1.5));
    let zeroFive = theme->Styles.getSpacingMultipler(`Float(0.5));
    {
      root:
        Styles.(
          make([
            height(theme->getSpacing(6)),
            borderRadius(theme->getSpacing(2)),
            padding4(
              ~top=oneFive,
              ~bottom=oneFive,
              ~right=oneFive,
              ~left=zeroFive,
            ),
            unsafe("box-shadow", theme->MaterialUi_Theme.Theme.shadowsGet[4]),
            selector("& .fa-php", [width(em(1.2))]),
            selector("& .fa-gem", [width(em(1.2))]),
          ])
        ),
    };
  })
];

[@react.component]
let make = (~name, ~iconClass=?, ~logo=?) => {
  let classes = SkillChip.useStyles();
  let color = `Primary;
  let label = name->React.string;
  let className = classes.root;

  switch (iconClass, logo) {
  | (Some(ic), _) =>
    let icon = <MaterialUi.Icon className=ic />;
    <MaterialUi.Chip className label icon color />;
  | (None, Some(src)) =>
    let avatar = <MaterialUi.Avatar src alt=name />;
    <MaterialUi.Chip className label avatar color />;
  | _ => <MaterialUi.Chip className label color />
  };
};