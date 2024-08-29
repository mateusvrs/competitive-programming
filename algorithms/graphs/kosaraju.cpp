vi adj[MAX], rev[MAX];
bitset<MAX> visited;

void dfs(int u, vi& order)
{
    if (visited[u])
        return;

    visited[u] = true;

    for (auto v : adj[u])
        dfs(v, order);

    order.emplace_back(u);
}

vi dfs_order(int N)
{
    vi order;

    for (int u = 1; u <= N; ++u)
        dfs(u, order);

    return order;
}

void dfs_cc(int u, vi& cc)
{
    if (visited[u])
        return;

    visited[u] = true;
    cc.emplace_back(u);

    for (auto v : rev[u])
        dfs_cc(v, cc);
}

vector<vi> kosaraju(int N) {
    auto order = dfs_order(N);
    reverse(order.begin(), order.end());

    for (int u = 1; u <= N; ++u)
        for (auto v : adj[u])
            rev[v].emplace_back(u);

    vector<vi> cs;
    visited.reset();

    for (auto u : order) {
        if (visited[u])
            continue;

        cs.emplace_back(vi());
        dfs_cc(u, cs.back());
    }
        
    return cs;
}
