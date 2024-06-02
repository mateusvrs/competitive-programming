class SuffixAutomaton {
public:
    struct state {
        int len, link;
        array<int, 26> next;
    };

    vector<state> st;
    int sz = 0, last;

    SuffixAutomaton(const string& s) : st(s.size() << 1) {
        sa_init();
        for (auto v : s) sa_extend((int)(v - 'a'));
    }

    void sa_init() {
        st[0].len = 0;
        st[0].link = -1;
        sz++; last = 0;
    }

    void sa_extend(int c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && !st[p].next[c]) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) st[cur].link = q;
            else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].link = st[q].link;
                st[clone].next = st[q].next;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    // longest common substring O(N)
    int lcs(const string& T) {
        int v = 0, l = 0, best = 0;
        for (int i = 0; i < T.size(); i++) {
            while (v && !st[v].next[T[i] - 'a']) {
                v = st[v].link;
                l = st[v].len;
            }
            if (st[v].next[T[i] - 'a']) {
                v = st[v].next[T[i] - 'a'];
                l++;
            }
            best = max(best, l);
        }
        return best;
    }
};