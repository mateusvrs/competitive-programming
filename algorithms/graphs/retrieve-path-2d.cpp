vll Graph::retrieve_path_2d(ll src, ll trg, const vector<vl>& pred) {
  vll p;

  do {
    p.emplace_back(pred[src][trg], trg);
    trg = pred[src][trg];
  } while (trg != src);

  reverse(all(p));

  return p;
}