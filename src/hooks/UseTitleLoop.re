let titles = [|
  "software architect",
  "software engineer",
  "UI engineer",
  "technical leader",
  "mentor",
|];

let useTitleLoop = (~delay=500, ~loopStarted) => {
  let titleIncrement = React.useRef(0);
  let (title, setTitle) =
    React.useState(() => titles[React.Ref.current(titleIncrement)]);
  React.useEffect1(
    () => {
      let intervalId: ref(option(Js_global.intervalId)) = ref(None);
      Js.Global.setTimeout(
        () => {
          intervalId :=
            loopStarted
              ? Some(
                  Js_global.setInterval(
                    () => {
                      let curr = titleIncrement->React.Ref.current;
                      if (curr < titles->Array.length - 1) {
                        titleIncrement->React.Ref.setCurrent(curr + 1);
                      } else {
                        titleIncrement->React.Ref.setCurrent(0);
                      };
                      setTitle(_ => titles[titleIncrement->React.Ref.current]);
                      ();
                    },
                    1000,
                  ),
                )
              : None;
          ();
        },
        delay,
      );

      Some(
        () => {
          switch (intervalId^) {
          | Some(id) => Js.Global.clearInterval(id)
          | None => ()
          }
        },
      );
    },
    [|loopStarted|],
  );
  title;
};