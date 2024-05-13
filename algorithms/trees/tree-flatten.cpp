vll tree_flatten(ll root) {
  vl pre;
  pre.reserve(N);

  vll flat(N);
  ll timer = -1;
  auto dfs = [&](auto&& self, ll u, ll p) -> void {
    timer++;
    pre.push_back(u);
    for (auto [v, w] : adj[u])
      if (v != p) {
        self(self, v, u);
      }
    flat[u].second = timer;
  };
  dfs(dfs, root, -1);
  for (ll i = 0; i < (ll)N; i++) flat[pre[i]].first = i;
  return flat;
}