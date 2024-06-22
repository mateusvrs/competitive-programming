template<typename T>
class SegTreeLazy {
private:
    int N;
    vector<T> seg, lzy;

    void down(int k, int l, int r) {
        seg[k] += (r - l + 1) * lzy[k];
        if (l < r) {
            lzy[k << 1] += lzy[k];
            lzy[k << 1 | 1] += lzy[k];
        }
        lzy[k] = 0;
    }

    void update(int i, int j, int k, int l, int r, T v) {
        if (lzy[k]) down(k, l, r);
        if (i > r or j < l) return;
        if (i <= l and j >= r) {
            seg[k] += (r - l + 1) * v;
            if (l < r) {
                lzy[k << 1] += v;
                lzy[k << 1 | 1] += v;
            }
            return;
        }

        update(i, j, k << 1, l, (l + r) / 2, v);
        update(i, j, k << 1 | 1, (l + r) / 2 + 1, r, v);
        seg[k] = seg[k << 1] + seg[k << 1 | 1];
    }

    T query(int i, int j, int k, int l, int r) {
        if (lzy[k]) down(k, l, r);
        if (i > r or j < l) return 0;
        if (i <= l and j >= r) return seg[k];

        T lft = query(i, j, k << 1, l, (l + r) / 2);
        T rgt = query(i, j, k << 1 | 1, (l + r) / 2 + 1, r);
        return lft + rgt;
    }

public:
    SegTreeLazy(int N) : N(N), seg(N << 2, 0), lzy(N << 2, 0) {}

    void update(int i, int j, T v) { update(i, j, 1, 0, N - 1, v); }

    T query(int i, int j) { return query(i, j, 1, 0, N - 1); }
};
