vii adj[MAX];

pair<vector<vi>, vector<vi>>
floyd_warshall(int N)
{
    vector<vi> dist(N + 1, vi(N + 1, oo));
    vector<vi> pred(N + 1, vi(N + 1, oo));

    for (int u = 1; u <= N; ++u)
    {
        dist[u][u] = 0;
        pred[u][u] = u;
    }

    for (int u = 1; u <= N; ++u)
        for (auto [v, w] : adj[u]) {
            dist[u][v] = w;
            pred[u][v] = u;
        }

    for (int k = 1; k <= N; ++k)
    {
        for (int u = 1; u <= N; ++u)
        {
            for (int v = 1; v <= N; ++v)
            {
                if (dist[u][k] < oo and dist[k][v] < oo 
                    and dist[u][v] > dist[u][k] + dist[k][v]) {
                        dist[u][v] = dist[u][k] + dist[k][v];
                        pred[u][v] = pred[k][v];
                }
            }
        }
    }

    return { dist, pred };
}

vii path(int u, int v, const vector<vi>& pred)
{
    vii p;

    do {
        p.push_back(ii(pred[u][v], v));
        v = pred[u][v];
    } while (v != u);

    reverse(all(p));

    return p;
}