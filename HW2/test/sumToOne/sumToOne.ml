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

let d = 0.85

let test_step_pagerank_sum () =
  let initial_ranks = initPageRank g0 in
  let new_ranks = stepPageRank initial_ranks d g0 in
  let total_rank = PageRank.fold (fun _ v acc -> acc +. v) new_ranks 0.0 in
  let rounded_total = Float.round total_rank in
  check (float 0.0001) "Sum of PageRanks should be 1" 1.0 rounded_total

let () =
  run "sumToOne Test"
    [
      ( "sumToOne",
        [
          test_case "Check sum of PageRanks after step" `Quick
            test_step_pagerank_sum;
        ] );
    ]
