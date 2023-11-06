class Graph {
 private:
  ll N;
  bool undirected;
  vector<vll> adj;

 public:
  Graph(ll N, bool is_undirected = true) {
    this->N = N;
    adj.resize(N);
    undirected = is_undirected;
  }

  void add(ll u, ll v, ll w) {
    adj[u].emplace_back(v, w);
    if (undirected) adj[v].emplace_back(u, w);
  }

  vl dijkstra(ll src);

  pair<vl, vl> dijkstra_path(ll src);

  vll retrieve_path(ll s, ll u, const vl& pred);
};