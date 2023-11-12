using edge = tuple<int, int, int>;

pair<int, vi>
kruskal(int N, vector<edge>& es, int blocked = -1)
{
    vi mst;
    UnionFind ufds(N);
    int cost = 0;

    for (int i = 0; i < (int) es.size(); ++i)
    {
        auto [w, u, v] = es[i];

        if (i != blocked and not ufds.same_set(u, v)) {
            cost += w;
            ufds.union_set(u, v);
            mst.emplace_back(i);
        }
    }

    return { (int) mst.size() == N - 1 ? cost : oo, mst };
}

int second_best(int N, vector<edge>& es)
{
    sort(es.begin(), es.end());

    auto [_, mst] = kruskal(N, es);
    int best = oo;

    for (auto blocked : mst)
    {
        auto [cost, __] = kruskal(N, es, blocked);
        best = min(best, cost);
    }

    return best;
}
