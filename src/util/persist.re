external getItem : string => option string =
  "localStorage.getItem" [@@bs.val] [@@bs.return null_to_opt];

external setItem : string => string => unit = "localStorage.setItem" [@@bs.val];

external unsafeJsonParse : string => 'a = "JSON.parse" [@@bs.val];

let namespace = "rr-playground";

let loadLocally item => {
  let key = namespace ^ "-" ^ item;
  switch (getItem key) {
  | None => []
  | Some data => unsafeJsonParse data
  }
};

let saveLocally data name => {
  let key = namespace ^ "-" ^ name;
  switch (Js.Json.stringifyAny data) {
  | None => ()
  | Some stringifiedData => setItem key stringifiedData
  }
};
