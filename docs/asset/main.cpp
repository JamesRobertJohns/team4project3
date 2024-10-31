int main() {
  int C, n; vector<int> w, p;
  cin >> C; cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    w.push_back(tmp);
  }
  for (int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    p.push_back(tmp);
  }
  cout << dp(w, p, C) << "\n";
  cout << dpp(w, p, C) << "\n";
}
