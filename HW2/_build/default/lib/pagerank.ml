module PageRank = Map.Make(String)
module PageSet = Set.Make(String)

(*
    Homework 2: Implementing Pagerank
    cc: Akshar Patel (akshar20@uab.edu), Michael Gathara (mikegtr@uab.edu)

    Pagerank is a popular graph algorithm used for information retrieval and 
    was popularized by Google as the core algorithm powering the Google 
    search engine. We will discuss the pagerank algorithm in lab, but we 
    encourage you to learn more about it using the internet. Here, you will 
    implement several functions that implement the PageRank algorithm in OCaml.

    Hints:

    - You can assume that no graph will include self-links and that each page
      will link to at least one other page.

    - You can assume that there will be no repeat links in the graph

    - You can define your own functions if you want to break up complicated 
      function definitions

    - Do not change the core (the ones we give here) function signatures

    Submission:
    - On Canvas: Required: This file, ICF, Report (pdf)
    - On Github: Required: This file  
                 Optional: ICF & Report 
*)



(*
   numPages: Computes the total number of pages present in the graph.
   For example, for the graph [("n0", "n1"); ("n1", "n2")], the result is 3
   since the pages are "n0", "n1", and "n2"
   Input: graph as a list of (string * string) tuples (each representing a
   link from one page to another)
   Output: int representing the number of unique pages in the graph
*)





let numPages graph =

  let pages = ref [] in


  List.iter (fun (a, b) ->
    if not (List.mem a !pages) then 
      pages := a :: !pages;
    if not (List.mem b !pages) then 
      pages := b :: !pages;
  ) graph;

  List.length !pages













(*
   numLinks: Computes the number of outbound links from the given page.
   For example, given the graph [("n0", "n1"); ("n1", "n0"); ("n0", "n2")]
   and the page "n0", the function should return 2 because "n0" links to
   "n1" and "n2".
   
   Input: 
     - graph: a list of (string * string) representing the graph's links
     - page: a string representing the page whose outbound links are to be
       counted
   Output:
     - int representing the number of links emanating from the given page
*)





let numLinks graph page =

  List.fold_left(fun amnt (a, _) ->
    if a = page then amnt + 1 else amnt
  ) 0 graph





(*
(*
   getBacklinks: Computes the set of pages that link to the given page.
   For example, in the graph [("n0", "n1"); ("n1", "n2"); ("n0", "n2")] and
   the page "n2", the function should return a set containing "n0" and "n1".
   
   Input:
     - graph: a list of (string * string) representing the graph's links
     - page: a string representing the page for which backlinks are sought
   Output:
     - PageSet.t (set of strings) representing all pages that link to
       the given page
*)
let getBacklinks graph page =
    raise (Failure "TODO: implement getBacklinks")

(*
   initPageRank: Generates the initial PageRank for the given graph.
   Each page is assigned an equal rank of 1/N, where N is the total number
   of pages, so that the sum of all page ranks is 1.
   
   Input: graph as a list of (string * string) representing the graph
   Output: a PageRank map (string -> float) with each page mapped to its
   initial rank (1/N)
*)
let initPageRank graph =
    raise (Failure "TODO: implement initPageRank")

(*
   stepPageRank: Performs one iteration step of the PageRank algorithm
   on the graph, updating every page with a new weight.
   The new rank for each page is calculated using the formula:
   
       NewRank(page) = (1 - d) / N + d * S

   where:
     - d is the damping factor (a float between 0 and 1, e.g., 0.85)
     - N is the total number of pages in the graph
     - S is the sum, over all pages that link to the current page, of
       (CurrentRank(page_j) / numLinks(page_j))
   
   Input:
     - pr: current PageRank map (string -> float)
     - d: damping factor (float)
     - graph: list of (string * string) representing the graph's links
   Output:
     - updated PageRank map (string -> float) after one iteration
       of the algorithm
*)
let stepPageRank pr d graph =
    raise (Failure "TODO: implement stepPageRank")

(*
   iterPageRank: Iterates the PageRank algorithm until convergence.
   The function repeatedly applies the stepPageRank function until
   the largest change in any page's rank is less than the specified
   delta.
   
   Input:
     - pr: initial PageRank map (string -> float)
     - d: damping factor (float)
     - graph: list of (string * string) representing the graph's links
     - delta: a threshold (float) such that iteration stops when the
       maximum change is less than delta
   Output:
     - a converged PageRank map (string -> float) where the maximum
       rank change is below delta
*)
let iterPageRank pr d graph delta =
    raise (Failure "TODO: implement iterPageRank")

(*
   rankPages: Produces a ranked list of pages from the PageRank map.
   The list is sorted in ascending order based on each page's
   PageRank value (from least popular to most popular).
   It is assumed that no two pages have the same rank.
   
   Input: pr: PageRank map (string -> float)
   Output: a list of pages (strings) sorted in ascending order by
   their rank values
*)
let rankPages pr =
    raise (Failure "TODO: implement rankPages")
*)