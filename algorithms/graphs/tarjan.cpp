enum State { NOT_FOUND, FOUND, PROCESSED };

vi adj[MAX];

bool dfs(int u, vi& o, vi& state)
{
    if (state[u] == PROCESSED)
        return true;

    if (state[u] == FOUND)
        return false;

    state[u] = FOUND;

    for (auto v : adj[u])
        if (not dfs(v, o, state))
            return false;

    state[u] = PROCESSED;
    o.emplace_back(u);

    return true;
}

vi topological_sort(int N)
{
    vi o, state(N + 1, NOT_FOUND);

    
    for (int u = 1; u <= N; ++u)
        if (state[u] == NOT_FOUND and not dfs(u, o, state))
            return { };

    reverse(o.begin(), o.end());

    return o;
}