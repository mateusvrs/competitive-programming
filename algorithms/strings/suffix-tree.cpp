const int aph = 27; // add $ to final of string
const int N = 2e5 + 31;
class SuffixTree {
public:
    string a;
    vector<array<int, aph>> t;
    vector<int> l, r, p, s, dst;
    int tv, tp, ts, la, b;

    SuffixTree(const string& str, char bs = 'a') : a(str), t(N), l(N),
        r(N, str.size() - 1), p(N), s(N), dst(N), b(bs) {
        build();
    }

    void ukkadd(int c) {
    suff:;
        if (r[tv] < tp) {
            if (t[tv][c] == -1) {
                t[tv][c] = ts; l[ts] = la;
                p[ts++] = tv; tv = s[tv]; tp = r[tv] + 1; goto suff;
            }
            tv = t[tv][c]; tp = l[tv];
        }
        if (tp == -1 || c == a[tp] - b) tp++; else {
            l[ts + 1] = la; p[ts + 1] = ts;
            l[ts] = l[tv]; r[ts] = tp - 1; p[ts] = p[tv];
            t[ts][c] = ts + 1; t[ts][a[tp] - b] = tv; l[tv] = tp;
            p[tv] = ts; t[p[ts]][a[l[ts]] - b] = ts; ts += 2;
            tv = s[p[ts - 2]]; tp = l[ts - 2];
            while (tp <= r[ts - 2]) {
                tv = t[tv][a[tp] - b];
                tp += r[tv] - l[tv] + 1;
            }
            if (tp == r[ts - 2] + 1) s[ts - 2] = tv; else s[ts - 2] = ts;
            tp = r[tv] - (tp - r[ts - 2]) + 2; goto suff;
        }
    }

    void build() {
        ts = 2; tv = 0; tp = 0;
        s[0] = 1; l[0] = -1; r[0] = -1; l[1] = -1; r[1] = -1;
        for (auto& arr : t) { arr.fill(-1); } t[1].fill(0);
        for (la = 0; la < (int)a.size(); ++la) ukkadd(a[la] - b);
    }
};