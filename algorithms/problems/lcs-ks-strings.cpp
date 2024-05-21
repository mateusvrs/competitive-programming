int lcs_ks_strings(vector<string>& sts, int k) {
  vi fml;
  string t;
  for (int i = 0; i < k; i++) {
    t += sts[i];
    for (int j = 0; j < sts[i].size(); j++) fml.push_back(i);
  }

  vi p = suffix_array(t);
  deque<int> lcp = lcp_suffix_array(t, p);
  lcp.push_front(0);

  int l = 0, r = 0, cnt = 0, lcs = 0, n = p.size();
  vector<int> fr(k + 1);
  multiset<int> mst;
  while (l < n) {
    while (r < n and cnt < k) {
      mst.insert(lcp[r]);
      if (!fr[fml[p[r]]]++) cnt++;
      r++;
    }
    mst.erase(mst.find(lcp[l]));
    if (mst.size() and cnt == k) lcs = max(lcs, *mst.begin());
    fr[fml[p[l]]]--;
    if (!fr[fml[p[l]]]) cnt--;
    l++;
  }

  return lcs;
}