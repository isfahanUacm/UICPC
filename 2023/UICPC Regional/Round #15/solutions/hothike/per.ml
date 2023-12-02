let n = int_of_string(read_line());;
let x = List.map int_of_string (String.split_on_char ' ' (read_line()));;
let rec solve i =
  if i+2 >= n then (50, 0)
  else min (max (List.nth x i) (List.nth x (i+2)), i+1) (solve (i+1));;
Printf.printf "%d %d\n" (snd (solve 0)) (fst (solve 0));;
