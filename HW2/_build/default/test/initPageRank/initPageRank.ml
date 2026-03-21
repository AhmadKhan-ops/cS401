open Alcotest
open Pagerank

let g0 =
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

let expected_ranks =
  [
    ("n0", 1.0 /. 5.0);
    ("n1", 1.0 /. 5.0);
    ("n2", 1.0 /. 5.0);
    ("n3", 1.0 /. 5.0);
    ("n4", 1.0 /. 5.0);
  ]

let round_float f =
  let factor = 10000.0 in
  floor ((f *. factor) +. 0.5) /. factor

let test_init_pagerank () =
  let computed_ranks = initPageRank g0 in
  List.iter
    (fun (node, expected) ->
      let actual = PageRank.find node computed_ranks |> round_float in
      let expected = round_float expected in
      check (float 0.0001) ("Initial PageRank for " ^ node) expected actual)
    expected_ranks

let () =
  run "initPageRank Tests"
    [
      ( "initPageRank",
        [ test_case "Check initial pagerank" `Quick test_init_pagerank ] );
    ]
