vector<pll> adj[MAX];
class Graph {
 public:
  void add(ll u, ll v, ll w) {
    adj[u].emplace_back(v, w);
    // Undirected Graph
    // adj[u].emplace_back(v, w);
  }

  vl dijkstra(ll src, ll n) {
    vl ds(n, LLONG_MAX);
    ds[src] = 0;
    set<pll> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
      ll u = pq.begin()->second;
      ll wu = pq.begin()->first;
      pq.erase(pq.begin());

      if (wu != ds[u]) continue;
      for (auto [v, w] : adj[u]) {
        if (ds[v] > ds[u] + w) {
          ds[v] = ds[u] + w;
          pq.emplace(ds[v], v);
        }
      }
    }

    return ds;
  }
};