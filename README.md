# Competitive Programming

In this repository, you'll find algorithms and data structure implementations for competitive programming, along with a [printable notebook](./notebook.pdf) with the implementations

## Algorithms

- Data Structures
  - [ufds](/algorithms/data-structures/ufds.cpp)

- Dynamic Programming
  - [kadane](/algorithms/dynamic-programming/kadane.cpp)
  - [lis](/algorithms/dynamic-programming/lis.cpp)

- Graphs
  - [dijkstra](/algorithms/graphs/dijkstra.cpp)

- Math
  - [binomial](/algorithms/math/binomial.cpp)
  - [convex hull](/algorithms/math/convex-hull.cpp)
  - [factorization](/algorithms/math/factorization.cpp)
  - [factorization with sieve](/algorithms/math/factorization-with-sieve.cpp)
  - [fast exp](/algorithms/math/fast-exp.cpp)
  - [fast exp iterative](/algorithms/math/fast-exp-iterative.cpp)
  - [gcd](/algorithms/math/gcd.cpp)
  - [is prime](/algorithms/math/is-prime.cpp)
  - [lcm](/algorithms/math/lcm.cpp)
  - [phi](/algorithms/math/phi.cpp)
  - [point to segment](/algorithms/math/point-to-segment.cpp)
  - [sieve](/algorithms/math/sieve.cpp)

- Problems
  - [kth digit string](/algorithms/problems/kth-digit-string.cpp)

- Strings
  - [manacher](/algorithms/strings/manacher.cpp)

- Trees
  - [lca binary lifting (cp algo)](/algorithms/trees/lca-binary-lifting-(cp-algo).cpp)
  - [lca segtree](/algorithms/trees/lca-segtree.cpp)
  - [lca sparse table](/algorithms/trees/lca-sparse-table.cpp)
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

From that, you can delete the algorithms inside the `algorithms` folder and add your own inside the same `algorithms` folder that are empty now. To customize the README.md, you can edit the `scripts/gen-readme.py` file. Finally, you can edit the university logo changing the `assets/logo.jpg` file (keeping the same name and extension).

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
