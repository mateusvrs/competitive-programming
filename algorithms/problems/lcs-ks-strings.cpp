int lcs_ks_strings(vector<string>& sts, int k) {
  vector<int> fml;
  string t;
  for (int i = 0; i < k; i++) {
    t += sts[i];
    for (int j = 0; j < sts[i].size(); j++) fml.push_back(i);
  }

  suffix_array sf(t);
  sf.lcp.insert(sf.lcp.begin(), 0);

  int l = 0, r = 0, cnt = 0, lcs = 0, n = sf.sa.size();
  vector<int> fr(k + 1);
  multiset<int> mst;
  while (l < n) {
    while (r < n and cnt < k) {
      mst.insert(sf.lcp[r]);
      if (!fr[fml[sf.sa[r]]]++) cnt++;
      r++;
    }
    mst.erase(mst.find(sf.lcp[l]));
    if (mst.size() and cnt == k) lcs = max(lcs, *mst.begin());
    fr[fml[sf.sa[l]]]--;
    if (!fr[fml[sf.sa[l]]]) cnt--;
    l++;
  }

  return lcs;
}