const int MAX{100010};

vector<ii> adj[MAX];

int prim(int u, int N) {
  set<int> C;
  C.insert(u);

  priority_queue<ii, vector<ii>, greater<ii>> pq;

  for (auto [v, w] : adj[u]) pq.push(ii(w, v));

  int mst = 0;

  while ((int)C.size() < N) {
    int v, w;

    do {
      w = pq.top().first, v = pq.top().second;
      pq.pop();
    } while (C.count(v));

    mst += w;
    C.insert(v);

    for (auto [s, p] : adj[v]) pq.push(ii(p, s));
  }

  return mst;
}