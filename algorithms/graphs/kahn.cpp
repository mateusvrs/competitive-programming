unordered_set<int> in[MAX], out[MAX];

vi topological_sort(int N) {
  vi o;
  queue<int> q;

  for (int u = 1; u <= N; ++u)
    if (in[u].empty()) q.push(u);

  while (not q.empty()) {
    auto u = q.front();
    q.pop();

    o.emplace_back(u);

    for (auto v : out[u]) {
      in[v].erase(u);

      if (in[v].empty()) q.push(v);
    }
  }

  return (int)o.size() == N ? o : vi{};
}