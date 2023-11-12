using edge = tuple<int, int, int>;

int msf(int k, int N, vector<edge>& es)
{
    sort(es.begin(), es.end());

    int cost = 0, cc = N;
    UnionFind ufds(N);

    for (auto [w, u, v] : es)
    {
        if (not ufds.same_set(u, v)) {
            cost += w;
            ufds.union_set(u, v);

            if (--cc == k)
                return cost;
        }
    }

    return cost;
}