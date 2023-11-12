using edge = tuple<int, int, int>;

const int MAX { 100010 };

vector<ii> adj[MAX];

int msg(int N, const vector<edge>& es)
{
    set<int> C;
    priority_queue<ii, vii, greater<ii>> pq;
    int cost = 0;

    for (auto [u, v, w] : es)
    {
        cost += w;

        C.insert(u);
        C.insert(v);

        for (auto [r, s] : adj[u])
            pq.push(ii(s, r));

        for (auto [r, s] : adj[v])
            pq.push(ii(s, r));
    }

    while ((int) C.size() < N)
    {
        int v, w;

        do {
            w = pq.top().first, v = pq.top().second;
            pq.pop();
        } while (C.count(v));

        cost += w;
        C.insert(v);

        for (auto [s, p] : adj[v])
            pq.push(ii(p, s));
    }

    return cost;
}
