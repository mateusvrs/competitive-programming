int dist[MAX][MAX];
vector<ii> adj[MAX];

vector<vi> floyd_warshall(int N)
{
    vector<vi> dist(N + 1, vi(N + 1, oo));

    for (int u = 1; u <= N; ++u)
        dist[u][u] = 0;

    for (int u = 1; u <= N; ++u)
        for (auto [v, w] : adj[u])
            dist[u][v] = w;

    for (int k = 1; k <= N; ++k)
        for (int u = 1; u <= N; ++u)
            for (int v = 1; v <= N; ++v)
                if (dist[u][k] < oo and dist[k][v] < oo)
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);

    return dist;
}