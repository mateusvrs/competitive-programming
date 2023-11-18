vii adj[MAX];

int minimax(int u, int N) {
  set<int> C;
  C.insert(u);

  priority_queue<ii, vii, greater<ii>> pq;

  for (auto [v, w] : adj[u]) pq.push(ii(w, v));

  int minmax = -oo;

  while ((int)C.size() < N) {
    int v, w;

    do {
      w = pq.top().first, v = pq.top().second;
      pq.pop();
    } while (C.count(v));

    minmax = max(minmax, w);
    C.insert(v);

    for (auto [s, p] : adj[v]) pq.push(ii(p, s));
  }

  return minmax;
}
