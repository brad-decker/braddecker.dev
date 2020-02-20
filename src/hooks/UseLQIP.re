open Webapi.Dom;

type mode = [ | `css | `src];
type return =
  | StyleObject(ReactDOMRe.Style.t)
  | ImageSrc(string);

let useLQIP = (~mode=`src, ~placeholder: string, ~full: string) => {
  let (loaded, setLoaded) = React.useState(() => false);
  let img = React.useRef(Js.Nullable.null);
  Js.Console.log(loaded);
  React.useEffect0(() => {
    React.Ref.(img->setCurrent(Js.Nullable.return(HtmlImageElement.make())));
    switch (Js.Nullable.toOption(React.Ref.current(img))) {
    | Some(element) =>
      HtmlImageElement.addLoadEventListener(
        _ => {
          Js.Console.log("here");
          setLoaded(_ => true);
          React.Ref.(img->setCurrent(Js.Nullable.null));
        },
        element,
      );
      element->HtmlImageElement.setSrc(full);
    | None => ()
    };
    None;
  });
  let fullUrl = {j|url($full)|j};
  let placeholderUrl = {j|url($placeholder)|j};
  switch (mode, loaded) {
  | (`css, true) =>
    StyleObject(ReactDOMRe.Style.make(~backgroundImage=fullUrl, ()))
  | (`css, false) =>
    StyleObject(ReactDOMRe.Style.make(~backgroundImage=placeholderUrl, ()))
  | (`src, true) => ImageSrc(full)
  | (`src, false) => ImageSrc(placeholder)
  };
};