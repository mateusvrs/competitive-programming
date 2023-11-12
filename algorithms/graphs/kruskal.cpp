using edge = tuple<int, int, int>;

int kruskal(int N, vector<edge>& es) {
  sort(es.begin(), es.end());

  int cost = 0;
  UnionFind ufds(N);

  for (auto [w, u, v] : es) {
    if (not ufds.same_set(u, v)) {
      cost += w;
      ufds.union_set(u, v);
    }
  }

  return cost;
}