#include <bits/stdc++.h>
using namespace std;

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
