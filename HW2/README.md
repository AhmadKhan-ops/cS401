# Academic Integrity Declaration

**I declare that:**
- **I have completed this assignment entirely on my own.**
- **I understand and have complied with the course policy on the use of AI tools.**
- **I have read the UAB Academic Integrity Code and understand that any breach of this code may result in severe penalties, including failure of the class.**

Name: <i><strong>PUT YOUR NAME HERE</strong></i>

# Project Deadline
<strong>03/09/2024 11:59 CST</strong>


# Project Set Up
```plaintext
CS401_HW2_PAGERANK
├── lib
│   ├── dune
│   ├── pagerank.ml
├── test
│   ├── getBacklinks
│   │   ├── dune
│   │   ├── getBacklinks.ml
│   ├── initPageRank
│   │   ├── dune
│   │   ├── initPageRank.ml
│   ├── iterPageRank
│   │   ├── dune
│   │   ├── iterPageRank.ml
│   ├── numLinks
│   │   ├── dune
│   │   ├── numLinks.ml
│   ├── numPages
│   │   ├── dune
│   │   ├── numPages.ml
│   ├── rankPages
│   │   ├── dune
│   │   ├── rankPages.ml
│   ├── stepPageRank
│   │   ├── dune
│   │   ├── stepPageRank.ml
├── sumToOne
│   ├── dune
│   ├── sumToOne.ml
├── .ocamlformat
├── cs401_hw2_pagerank.opam
├── dune-project
├── README.md
```
### `lib`
This section contains the Page Rank implementation in the file `pagerank.ml`. This should be the one and only file you need to edit to complete the coding potion of this homework. Although general instructions for the project are location in `README.md`, specific instructions on the functions you must implement for this project are in the docstrings for each function in `pagerank.ml`.

### `test`
This section contains the test cases that you must pass to get credit for the coding portion of this homework. You may look at the files (the `.ml` file within each test case) to see what the input(s) and expected ouput(s) of each test case is, but do not edit these files as it may mess with the testing system we have set up for you.

### `README.md`
That is this file you are reading right now with the general project instructions.

# Project Dependencies
### Ocaml Platform Tools
- install with `opam install ocaml-lsp-server odoc ocamlformat utop`
### Alcotest
- install with `opam install alcotest`



# Project Documentation
***NOTE: THE ONLY FILE YOU SHOULD BE EDITING IN THIS PROJECT IS `pagerank.ml`
### Running Tests
- Run all tests: `dune test`
- Run one test: `dune test <path_to_test_folder>`
    - e.g. `dune test test/getBacklinks`
- Clean current build to re-run passed tests: `dune clean`

### Top Level Environment
- Open Utop: `dune utop`
    - `utop` is a REPL environment you can use to mess with the functions you have implemented without editing your source ocde
    - Once `utop` is opened, all functions within your `pagerank.ml` file should be accessible to test in the repl by entering `Pagerank`

### Compile the Project
- run `dune build`
    - This is done automatically when running `dune runtest`

### Format Your Code with `ocamlformat`
- run `dune fmt`
    - If this runs into an error then you might need to run `ocamlformat --version` and fix the package's version number in `.ocamlformat`



# Report Requirements
### Historical Context
1. Can you briefly explain why PageRank was considered revolutionary - compare to the previous search engine ranking methods of the time

### Algorithm
1. Explain the core concept of PageRank in your own words. What does it measure and how?

### Your implementation
1. Describe your implementation approach and any key design decisions you made.
2. What was the most challenging part of implementing PageRank?

### Complexity
1.  What is the time complexity of **YOUR** implementation?



# Deliverables
### On Canvas
- Your `pagerank.ml` file
- Your project report as a PDF
- Your Independent Completion Form
### On Github
- Your `pagerank.ml` file
- Your project report as a PDF (optional)
- Your Independent Completion Form (optional)


# Rubric
| Criteria   | Weight |
| :-------- | :-------: |
| Coding | 80%   |
| Report | 20%    |
| Total    | 100%    |

