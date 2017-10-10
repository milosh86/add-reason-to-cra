let () = Js.log "Hello there!";

let print () => Js.log "Hey you!";

type date;

external create_date : unit => date = "Date" [@@bs.new];

external getDay : date => int = "getDate" [@@bs.send];

external getMonth : date => int = "" [@@bs.send];

external getFullYear : date => int = "" [@@bs.send];

let format d formatStr => {
  let day = Js.Date.getDay d;
  let month = Js.Date.getMonth d;
  let year = Js.Date.getFullYear d;
  let ret = ref "";
  String.iter
    (
      fun ch =>
        switch ch {
        | 'Y'
        | 'y' => ret := !ret ^ string_of_float year
        | 'M'
        | 'm' => ret := !ret ^ string_of_float month
        | 'D'
        | 'd' => ret := !ret ^ string_of_float day
        | c => ret := !ret ^ String.make 1 c
        }
    )
    formatStr;
  !ret
};

let format2 (d: date) formatStr => {
  let day = getDay d;
  let month = getMonth d + 1;
  let year = getFullYear d;
  let ret = ref "";
  String.iter
    (
      fun ch =>
        switch ch {
        | 'Y'
        | 'y' => ret := !ret ^ string_of_int year
        | 'M'
        | 'm' => ret := !ret ^ (month < 10 ? "0" ^ string_of_int month : string_of_int month)
        | 'D'
        | 'd' => ret := !ret ^ (day < 10 ? "0" ^ string_of_int day : string_of_int day)
        | c => ret := !ret ^ String.make 1 c
        }
    )
    formatStr;
  !ret
};