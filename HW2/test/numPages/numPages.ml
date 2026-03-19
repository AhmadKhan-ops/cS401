open Alcotest
open Pagerank

let g1 =
  [
    ("n2", "n0");
    ("n1", "n4");
    ("n4", "n0");
    ("n1", "n3");
    ("n2", "n1");
    ("n0", "n1");
    ("n3", "n4");
    ("n0", "n4");
    ("n4", "n1");
    ("n4", "n2");
    ("n1", "n0");
  ]

let g2 = []
let test_numpages_1 () = check int "numPages for g0" 5 (numPages g1)
let test_numpages_2 () = check int "numPages" 0 (numPages g2)

let () =
  run "NumPages Tests"
    [
      ( "numPages_1",
        [ test_case "Test numPages for graph g1" `Quick test_numpages_1 ] );
      ( "numPages_2",
        [ test_case "Test numPages for graph g2" `Quick test_numpages_2 ] );
    ]
