template<typename T, auto op>
class SegTree {
public:
    T e;
    ll N;
    vector<T> seg;

    SegTree(ll N, T e) : e(e), N(N), seg(N + N, e) { }

    void assign(ll i, T v) {
        i += N;
        seg[i] = v;
        for (i >>= 1; i; i >>= 1) seg[i] = op(seg[2 * i], seg[2 * i + 1]);
    }

    T query(ll l, ll r) {
        T la = e, ra = e;
        l += N; r += N;

        while (l <= r) {
            if (l & 1) la = op(la, seg[l++]);
            if (~r & 1) ra = op(seg[r--], ra);
            l >>= 1; r >>= 1;
        }

        return op(la, ra);
    }
};