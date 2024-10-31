#include <bits/stdc++.h>
using namespace std;

int dp(vector<int>& w, vector<int>& p, int C) {
  int n = w.size();
  vector<vector<int>> dp(n+1, vector<int>(C+1, 0));
  for (int i = 1; i <= n; i++) {
    for (int c = 1; c <= C; c++) {
      if (w[i-1] > c) 
        dp[i][c] = dp[i-1][c];  
      else 
        dp[i][c] = max(dp[i-1][c], dp[i][c-w[i-1]] + p[i-1]);
    }
  }
  return dp[n][C];
}

int dpp(vector<int>& w, vector<int>& p, int C) {
  int n = w.size();
  vector<int> dp(C+1, 0);
  for (int i = 0; i < n; i++) {
    for (int c = 1; c <= C; c++) {
      if (w[i] > c) 
        dp[c] = dp[c];  
      else 
        dp[c] = max(dp[c], dp[c-w[i]] + p[i]);
    }
  }
  return dp[C];
}

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
