# Competitive Programming

In this repository, you'll find algorithms and data structure implementations for competitive programming, along with a [printable notebook](./notebook.pdf) with the implementations

## Algorithms

- Data Structures
  - [matrix](/algorithms/data-structures/matrix.cpp)
  - [merge sort tree](/algorithms/data-structures/merge-sort-tree.cpp)
  - [mex](/algorithms/data-structures/mex.cpp)
  - [mex update](/algorithms/data-structures/mex-update.cpp)
  - [rmq](/algorithms/data-structures/rmq.cpp)
  - [segtree](/algorithms/data-structures/segtree.cpp)
  - [segtree2d](/algorithms/data-structures/segtree2d.cpp)
  - [segtreelazy](/algorithms/data-structures/segtreelazy.cpp)
  - [ufds](/algorithms/data-structures/ufds.cpp)
  - [wavelet tree](/algorithms/data-structures/wavelet-tree.cpp)

- Dynamic Programming
  - [kadane](/algorithms/dynamic-programming/kadane.cpp)
  - [lis](/algorithms/dynamic-programming/lis.cpp)

- Extras
  - [stream int128t](/algorithms/extras/stream-int128t.cpp)

- Geometry
  - [convex hull](/algorithms/geometry/convex-hull.cpp)
  - [point to segment](/algorithms/geometry/point-to-segment.cpp)
  - [polyominoes](/algorithms/geometry/polyominoes.cpp)

- Graphs
  - [articulation points](/algorithms/graphs/articulation-points.cpp)
  - [bellman ford](/algorithms/graphs/bellman-ford.cpp)
  - [bfs 01](/algorithms/graphs/bfs-01.cpp)
  - [bridges](/algorithms/graphs/bridges.cpp)
  - [cycle bellman ford](/algorithms/graphs/cycle-bellman-ford.cpp)
  - [cycle floyd warshall](/algorithms/graphs/cycle-floyd-warshall.cpp)
  - [dijkstra](/algorithms/graphs/dijkstra.cpp)
  - [floyd warshall](/algorithms/graphs/floyd-warshall.cpp)
  - [graph](/algorithms/graphs/graph.cpp)
  - [kahn](/algorithms/graphs/kahn.cpp)
  - [kruskal](/algorithms/graphs/kruskal.cpp)
  - [minimax](/algorithms/graphs/minimax.cpp)
  - [msf](/algorithms/graphs/msf.cpp)
  - [msg](/algorithms/graphs/msg.cpp)
  - [prim](/algorithms/graphs/prim.cpp)
  - [retrieve path](/algorithms/graphs/retrieve-path.cpp)
  - [retrieve path 2d](/algorithms/graphs/retrieve-path-2d.cpp)
  - [second best mst](/algorithms/graphs/second-best-mst.cpp)
  - [tarjan](/algorithms/graphs/tarjan.cpp)

- Math
  - [binomial](/algorithms/math/binomial.cpp)
  - [count divisors](/algorithms/math/count-divisors.cpp)
  - [count divisors range](/algorithms/math/count-divisors-range.cpp)
  - [factorization](/algorithms/math/factorization.cpp)
  - [factorization with sieve](/algorithms/math/factorization-with-sieve.cpp)
  - [fast doubling](/algorithms/math/fast-doubling.cpp)
  - [fast exp](/algorithms/math/fast-exp.cpp)
  - [fast exp iterative](/algorithms/math/fast-exp-iterative.cpp)
  - [fft](/algorithms/math/fft.cpp)
  - [gcd](/algorithms/math/gcd.cpp)
  - [integer mod](/algorithms/math/integer-mod.cpp)
  - [is prime](/algorithms/math/is-prime.cpp)
  - [lcm](/algorithms/math/lcm.cpp)
  - [phi](/algorithms/math/phi.cpp)
  - [sieve](/algorithms/math/sieve.cpp)
  - [sum divisors](/algorithms/math/sum-divisors.cpp)
  - [sum of diference](/algorithms/math/sum-of-diference.cpp)

- Problems
  - [kth digit string](/algorithms/problems/kth-digit-string.cpp)
  - [lcs ks strings](/algorithms/problems/lcs-ks-strings.cpp)
  - [substring order II](/algorithms/problems/substring-order-II.cpp)

- Strings
  - [aho corasick](/algorithms/strings/aho-corasick.cpp)
  - [edit distance](/algorithms/strings/edit-distance.cpp)
  - [lcp suffix array](/algorithms/strings/lcp-suffix-array.cpp)
  - [manacher](/algorithms/strings/manacher.cpp)
  - [rabin karp](/algorithms/strings/rabin-karp.cpp)
  - [suffix array](/algorithms/strings/suffix-array.cpp)
  - [suffix array op](/algorithms/strings/suffix-array-op.cpp)
  - [suffix automaton](/algorithms/strings/suffix-automaton.cpp)
  - [suffix tree](/algorithms/strings/suffix-tree.cpp)
  - [z function](/algorithms/strings/z-function.cpp)

- Trees
  - [lca binary lifting (cp algo)](/algorithms/trees/lca-binary-lifting-(cp-algo).cpp)
  - [lca segtree (cp algo)](/algorithms/trees/lca-segtree-(cp-algo).cpp)
  - [lca sparse table](/algorithms/trees/lca-sparse-table.cpp)
  - [tree flatten](/algorithms/trees/tree-flatten.cpp)
  - [tree isomorph](/algorithms/trees/tree_isomorph.cpp)

## Contributing

If you want to contribute to this repository, you can do it by adding new algorithms or improving the existing ones. To do so, you can follow the steps below:

1. Fork this repository
2. Add or improve the algorithm you want
3. Create a pull request
4. Wait for the pull request to be reviewed and merged

**Obs:** You don't need to update the notebook, because it is generated automatically. Just add the algorithm to the `algorithms` folder and make sure that you have added it to the correct category folder such as `algorithms/math`, `algorithms/graphs`, etc.

## How to run locally?

If you want to create your own notebook, it is possible as follows:

Clone the project repository with the following command:

```bash
git clone https://github.com/mateusvrs/competitive-programming.git
```

To run the project, you need to install the global dependencies, which are:

- Docker Engine v24 (or higher)

From that, you can delete the algorithms inside the `algorithms` folder and add your own inside the same `algorithms` folder that are empty now. To customize the README.md, you can edit the `scripts/gen-readme.py` file. Finally, you can edit the university logo changing the `assets/logo.jpg` file (keeping the same name and extension) and uncommenting line 57 at the file "scripts/notebook/template.tex".

Now, you can run the following command:

```bash
# Change the "Your Team Name" to the name of your own team
docker run -w /notebook -v .:/notebook mateusvrs/cp-notebook:v1.0 make team_name="Your Team Name"      
```

## References & Courses

- [TEP](https://github.com/edsomjr/TEP)
- [Competitive Programming Algorithms](https://github.com/iagorrr/Competitive-Programming-Algorithms)
- [UnBalloon](https://github.com/UnBalloon/programacao-competitiva)
- [Algorithms for Competitive Programming](https://cp-algorithms.com/)
- [Competitive Programing Book](https://cpbook.net/details?cp=4)
- [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf)
