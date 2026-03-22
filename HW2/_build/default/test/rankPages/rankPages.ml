open Alcotest
open Pagerank

let pr1 =
  let bindings =
    [
      ("node0", 339.0 /. 31250.0);
      ("node1", 131103.0 /. 1000000.0);
      ("node2", 144693.0 /. 500000.0);
      ("node3", 15689.0 /. 125000.0);
      ("node4", 131709.0 /. 500000.0);
      ("node5", 179733.0 /. 1000000.0);
    ]
  in
  List.fold_left
    (fun m (page, r) -> PageRank.add page r m)
    PageRank.empty bindings

let pr2 =
  let bindings =
    [
      ("node0", 897. /. 125000.);
      ("node1", 241. /. 4000.);
      ("node10", 62129. /. 1000000.);
      ("node11", 36377. /. 1000000.);
      ("node12", 26087. /. 1000000.);
      ("node13", 9187. /. 250000.);
      ("node14", 7969. /. 125000.);
      ("node15", 55093. /. 1000000.);
      ("node16", 61621. /. 1000000.);
      ("node17", 36843. /. 500000.);
      ("node18", 981. /. 25000.);
      ("node19", 15103. /. 500000.);
      ("node2", 29737. /. 500000.);
      ("node3", 14119. /. 250000.);
      ("node4", 17993. /. 250000.);
      ("node5", 16857. /. 500000.);
      ("node6", 63961. /. 1000000.);
      ("node7", 48997. /. 1000000.);
      ("node8", 68503. /. 1000000.);
      ("node9", 22269. /. 500000.);
    ]
  in
  List.fold_left
    (fun m (page, r) -> PageRank.add page r m)
    PageRank.empty bindings

let test_rankPages_1 () =
  let actual = rankPages pr1 in
  let expected = [ "node0"; "node3"; "node1"; "node5"; "node4"; "node2" ] in
  check (list string) "rankPages" expected actual

let test_rankPages_2 () =
  let actual = rankPages pr2 in
  let expected =
    [
      "node0";
      "node12";
      "node19";
      "node5";
      "node11";
      "node13";
      "node18";
      "node9";
      "node7";
      "node15";
      "node3";
      "node2";
      "node1";
      "node16";
      "node10";
      "node14";
      "node6";
      "node8";
      "node4";
      "node17";
    ]
  in
  check (list string) "rankPages" expected actual

let () =
  run "rankPages Tests"
    [
      ( "rankPages_1",
        [ test_case "Test rankPages for page rank pr1" `Quick test_rankPages_1 ]
      );
      ( "rankPages_2",
        [ test_case "Test rankPages for page rank pr2" `Quick test_rankPages_2 ]
      );
    ]
