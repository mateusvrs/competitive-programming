vll Graph::retrieve_path(ll src, ll trg, const vl& pred) {
  vll p;
  ll v = trg;

  do {
    p.emplace_back(pred[v], v);
    v = pred[v];
  } while (v != src);

  reverse(all(p));

  return p;
}