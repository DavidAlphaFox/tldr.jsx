[@bs.val]
external ext__setItem : (string, Js_types.obj_val) => unit =
  "window.localStorage.setItem";

[@bs.val]
external ext__getItem : string => Js.nullable(Js_types.obj_val) =
  "window.localStorage.getItem";

[@bs.val]
external ext__removeItem : string => unit = "window.localStorage.getItem";

module Dom: Storage.Key_value = {
  type t = Js_types.obj_val;
  let set = ext__setItem;
  let get = key => Js.toOption(ext__getItem(key));
  /* Lord knows why |> and |. did not work with Belt.Result.Ok */
  let remove = key => Belt.Result.Ok(ext__removeItem(key));
};