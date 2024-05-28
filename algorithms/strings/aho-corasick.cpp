const int K = 26;
struct Vertex {
  char pch;
  int next[K];
  bool check = false;
  int p = -1, lnk = -1, out = -1, ps = -1, d = 0;

  Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
    fill(begin(next), end(next), -1);
  }
};

class AhoCorasick {
 public:
  int sz = 0;  // number of strings added
  vector<Vertex> t;

  AhoCorasick() : t(1) {}

  void add_string(string const& s) {
    int v = 0, ds = 0;
    for (char ch : s) {
      int c = ch - 'a';
      if (t[v].next[c] == -1) {
        t[v].next[c] = t.size();
        t.emplace_back(v, ch);
      }
      v = t[v].next[c];
      t[v].d = ++ds;
    }
    t[v].check = true;
    t[v].ps = sz++;
  }

  void build() {
    queue<int> qs;
    qs.push(0);
    while (qs.size()) {
      auto u = qs.front();
      qs.pop();

      if (!t[u].p or t[u].p == -1)
        t[u].lnk = 0;
      else {
        int k = t[t[u].p].lnk;
        int c = t[u].pch - 'a';
        while (t[k].next[c] == -1 and k) k = t[k].lnk;
        int ts = t[k].next[c];
        if (ts == -1)
          t[u].lnk = 0;
        else
          t[u].lnk = ts;
      }

      if (t[t[u].lnk].check)
        t[u].out = t[u].lnk;
      else
        t[u].out = t[t[u].lnk].out;

      for (auto v : t[u].next)
        if (v != -1) qs.push(v);
    }
  }

  void occurrences(string const& s, vector<vector<int>>& res) {
    // to just "count" replace 'res' vector with an int
    res.resize(sz);
    for (int i = 0, v = 0; i < s.size(); i++) {
      int c = s[i] - 'a';
      while (t[v].next[c] == -1 and v) v = t[v].lnk;
      int ts = t[v].next[c];
      if (ts == -1)
        continue;
      else
        v = t[v].next[c];

      int k = v;
      while (t[k].out != -1) {
        k = t[k].out;
        res[t[k].ps].emplace_back(i - t[k].d + 1);
      }
      if (t[v].check) res[t[v].ps].emplace_back(i - t[v].d + 1);
    }
  }
};