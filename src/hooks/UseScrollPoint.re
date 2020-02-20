open Webapi.Dom;

let useScrollPoint = (~once=true, ()) => {
  let (target, setTarget) = React.useState(() => Js.Nullable.null);
  let (trigger, setTrigger) = React.useState(() => false);
  React.useEffect2(
    () => {
      let handleScroll = _ => {
        switch (Js.Nullable.toOption(target)) {
        | Some((element: Dom.element)) =>
          let top =
            element->Element.getBoundingClientRect->DomRect.top->int_of_float;
          let height = window->Window.innerHeight;
          if (top < height - 200) {
            setTrigger(_ => true);
          } else if (trigger && !once && top > height) {
            setTrigger(_ => false);
          };
        | None => ()
        };
      };
      Js_global.setTimeout(handleScroll, 500);
      Window.addEventListener("scroll", handleScroll, window);
      Some(
        () => {Window.removeEventListener("scroll", handleScroll, window)},
      );
    },
    (once, target),
  );

  (trigger, setTarget);
};