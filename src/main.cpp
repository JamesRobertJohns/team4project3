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

int dp_space_optimised(vector<int>& w, vector<int>& p, int C) {
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
  vector<int> w{ 4, 6, 8};
  vector<int> p{ 7, 6, 9};
  cout << dp(w, p, 14) << "\n";
  cout << dp_space_optimised(w, p, 14) << "\n";
}
