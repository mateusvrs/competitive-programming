using edge = tuple<int, int, int>;

vi bellman_ford(int s, int N, const vector<edge>& edges)
{
    vi dist(N + 1, oo);
    dist[s] = 0;

    for (int i = 1; i <= N - 1; i++)
        for (auto [u, v, w] : edges)
            if (dist[u] < oo and dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;

    return dist;
}