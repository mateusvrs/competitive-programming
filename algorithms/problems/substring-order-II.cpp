// ALLOWS REPETITIONS
string kth_smallest_substring(const string& s, ll k) {
  /* uses /strings/suffix-automaton.cpp
  add 'cnt' and 'nmb' to state struct with (0, -1);
      => for new states 'not cloned': cnt = 1

  create 'order' vector to iterate by length in decreasing
  vector<pair<int, int>>: {len, id}
      => for each new state add to 'order' vector

  to do not allow repetitions:
      => remove: kth+=s.size, sort(order) for(l, p : order)
      => add: st[clone].cnt = 1 (sa_extend)
  */
  string ans;
  k += s.size();
  SuffixAutomaton sa(s);

  sort(all(order), greater<pair<int, int>>());
  // count and mark how many times a substring of a state occurs
  for (auto& [l, p] : order) sa.st[sa.st[p].link].cnt += sa.st[p].cnt;

  auto dfs = [&](auto&& self, int u) {
    if (sa.st[u].nmb != -1) return;

    sa.st[u].nmb = sa.st[u].cnt;
    for (int i = 0; i < 26; ++i) {
      if (sa.st[u].next[i]) {
        self(self, sa.st[u].next[i]);
        sa.st[u].cnt += sa.st[sa.st[u].next[i]].cnt;
      }
    }
  };
  dfs(dfs, 0);

  int u = 0;
  while (sa.st[u].nmb < k) {
    k -= sa.st[u].nmb;
    for (int i = 0; i < 26; i++) {
      if (sa.st[u].next[i]) {
        int v = sa.st[u].next[i];
        if (sa.st[v].cnt < k)
          k -= sa.st[v].cnt;
        else {
          ans.push_back(i + 'a');
          u = v;
          break;
        }
      }
    }
  }

  return ans;
}