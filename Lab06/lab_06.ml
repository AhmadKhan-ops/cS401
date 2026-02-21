(*
    Lab 6: Introduction to Fold-left and Fold-right
    cc: Akshar Patel (akshar20@uab.edu), Michael Gathara (mikegtr@uab.edu)

    This assignment will help you familiarize yourself with two very
    important functions when it comes to functional programming, fold-left
    and fold-right. You will implement these functions yourself then
    implement various other functions that can use fold-left and fold-right.
    You will first implement each without using fold-left and fold-right
    followed by an implementation that does use fold-left and/or fold-right.

    After implementing these functions, please make a report:
        (1) explaining the differences in your implementations for fold-left
        and fold-right
        (2) discussing which functions required you to use fold-left and 
        which required fold-right, explaining why one was needed over the
        other

    Submission:
    - On Canvas: Required: This file, Report (pdf)
    - On Github: Required: This file  
                 Optional: Report 
*)




(*
    Fold-left: given an operator, accumulator, and list, iterate through
    the list left-to-right. With each iteration the function should
    combine the current value of the list to the accumulator using the
    input operator

    example: myFoldl + 0 [1; 2; 3; 4; 5] will output 15

    Input:
        - op: an operator for combining list value to the accumulator
        - acc: an accumulator
        - lst: a list of values
*)
let myFoldl op acc lst =
  let result = ref acc in          
  List.iter (fun x -> result := op !result x) lst;
  !result


(*
    Fold-right: given an operator, accumulator, and list, iterate through
    the list right-to-left. With each iteration the function should
    combine the current value of the list to the accumulator using the
    input operator

    example: myFoldr + [1; 2; 3; 4; 5] 0 will output 15

    Input:
        - op: an operator for combining list value to the accumulator
        - acc: an accumulator
        - lst: a list of values
*)
let myFoldr op lst acc =
  let result = ref acc in          
  List.rev lst |> List.iter (fun x -> result := op x !result );
  !result


(*
    Reverse: This function takes in a list and returns the reverse 
    of that list

    example: myReverse [1; 2; 3; 4] will output [4; 3; 2; 1]

    myReverse must be implemented without myFoldl and myFoldr while
    myReverseFold must be implemented with myFoldl and/or myFoldr

    Input:
        - acc: an optional accumulator argument (only for non-fold version)
        - lst: a list of values

    **NOTE: There are two major ways to implement the non-fold version
    of this function. One uses the acc optional argument while the other
    doesn't. We will go into the difference between the two next week,
    but for now just implement whichever makes more sense in your head. 
*)
let rec myReverse ?(acc=[]) lst =
  match lst with
  | [] -> acc
  | start :: end0  -> myReverse ~acc:(start :: acc) end0


let myReverseFold lst =
  myFoldl (fun acc x -> x :: acc) [] lst
    

(*
    Map: This function takes in a list and an operator and returns a
    list where every value has had that operator applied to them

    example: myMap (fun x -> x+1) [1; 2; 3; 4] will output [2; 3; 4; 5]

    myMap must be implemented without myFoldl and myFoldr while
    myMapFold must be implemented with myFoldl and/or myFoldr

    Input:
        - acc: an optional accumulator argument (only for non-fold version)
        - op: an operator
        - lst: a list of values

    **NOTE: There are two major ways to implement the non-fold version
    of this function. One uses the acc optional argument while the other
    doesn't. We will go into the difference between the two next week,
    but for now just implement whichever makes more sense in your head. 
*)
let rec myMap ?(acc=[]) op lst =
    match lst with
    | [] -> List.rev acc
    | head :: end0 -> myMap ~acc:(op head :: acc) op end0
let myMapFold op lst =
     myFoldr (fun x acc -> (op x) :: acc) lst []


(*
    Filter: This function takes in a list and a guard condition and returns a
    list only with the values that satisfy the guard condition

    example: myMap (fun x -> x mod 2 = 0) [1; 2; 3; 4] will output [2; 4]

    myFilter must be implemented without myFoldl and myFoldr while
    myFilterFold must be implemented with myFoldl and/or myFoldr

    Input:
        - acc: an optional accumulator argument (only for non-fold version)
        - guard: an operator that returns a boolean
        - lst: a list of values

    **NOTE: There are two major ways to implement the non-fold version
    of this function. One uses the acc optional argument while the other
    doesn't. We will go into the difference between the two next week,
    but for now just implement whichever makes more sense in your head. 
*)
let rec myFilter ?(acc=[]) guard lst =
    match lst with
    | [] -> List.rev acc 
    | head :: end0 -> 
        if guard head then
            myFilter ~acc:(head :: acc) guard end0
        else
            myFilter ~acc:acc guard end0



let myFilterFold guard lst =
    
    myFoldr (fun x acc -> if guard x then x :: acc else acc) lst []


let () =
    let func1 = myFoldl (+) 0 [1;2;3;4;5] in
    Printf.printf " Fold Left to Right is: %d\n " func1;

    let func2 = myFoldr (+) [1;2;3;4;5] 0 in
    Printf.printf "Fold Right to left is:  %d\n" func2;

    let func3 = myReverse [1;2;3;4;5] in
    print_string "Reverse of the list (non-fold) is: \n";
    List.iter (Printf.printf "%d ") func3;
    print_newline ();


    let func4 = myReverseFold [1;2;3;4;5] in
    print_string "Reverse of the list (fold) is: \n";
    List.iter (Printf.printf "%d ") func4;
    print_newline ();  

    let func5 = myMap (fun x -> x + 1) [1;2;3;4;5] in
    print_string "Map (non-fold) when its x + 1 is: \n";
    List.iter (Printf.printf "%d ") func5;
    print_newline ();
    
    let func6 = myMapFold (fun x -> x + 1) [1;2;3;4;5] in
    print_string "Map (fold) when its x + 1 is: \n";
    List.iter (Printf.printf "%d ") func6;
    print_newline ();
    
    let func7 = myFilter (fun x -> x mod 2 = 0) [1;2;3;4;5] in
    print_string "Filter (non-fold) for even numbers is : \n";
    List.iter (Printf.printf "%d ") func7;
    print_newline ();
    
    let func8 = myFilterFold (fun x -> x mod 2 = 0) [1;2;3;4;5] in
    print_string "Filter (fold) for even numbers is: \n ";
    List.iter (Printf.printf "%d ") func8;
    print_newline ()