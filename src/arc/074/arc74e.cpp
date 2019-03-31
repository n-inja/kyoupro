#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>

using namespace std;

typedef struct {
  int l, r, x;
} A;

const long long P = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<A> a(m);
  for(int i = 0; i < m; i++) cin >> a[i].l >> a[i].r >> a[i].x;
  vector<vector<vector<long long>>> dp(n + 1);
  vector<vector<pair<int, int>>> b(n + 1);
  for(int i = 0; i < m; i++) {
    b[a[i].r].push_back(make_pair(a[i].l, a[i].x));
  }
  for(int i = 0; i < n + 1; i++) {
    dp[i].resize(n + 1);
    for(int j = 0; j < n + 1; j++) dp[i][j].resize(n + 1);
  }
  long long ans = 0;
  dp[0][0][0] = 1;
  for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) for(int k = 0; k <= n; k++) {
    int maxCol = max(max(i, j), k);
    for(int l = 0; l < b[maxCol].size(); l++) {
      int count = 0;
      if(b[maxCol][l].first <= i) count++;
      if(b[maxCol][l].first <= j) count++;
      if(b[maxCol][l].first <= k) count++;
      if(b[maxCol][l].second != count) dp[i][j][k] = 0;
    }
    if(maxCol == n) ans = (ans + dp[i][j][k]) % P;
    else {
      dp[maxCol + 1][j][k] = (dp[maxCol + 1][j][k] + dp[i][j][k]) % P;
      dp[i][maxCol + 1][k] = (dp[i][maxCol + 1][k] + dp[i][j][k]) % P;
      dp[i][j][maxCol + 1] = (dp[i][j][maxCol + 1] + dp[i][j][k]) % P;
    }
  }
  cout << ans << endl;
  return 0;
}
