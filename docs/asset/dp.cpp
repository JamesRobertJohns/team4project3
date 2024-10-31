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
