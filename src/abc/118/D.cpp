#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int cost[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};

// K桁をN本使ってできたときの先頭の数字の最大
int dp[10101][10101] = {0};
int back[10101][10101] = {0};
bool ok[9] = {0};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    ok[a - 1] = true;
  }
  int k = n;
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= n; j++)
      dp[i][j] = back[i][j] = -1;
  }
  dp[0][0] = 0;
  for (int i = 0; i < k; i++)
    for (int j = 0; j < n; j++)
      for (int l = 0; l < 9; l++) {
        if (!ok[l] || dp[i][j] < 0)
          continue;
        if (j + cost[l] <= n && dp[i + 1][j + cost[l]] < l) {
          dp[i + 1][j + cost[l]] = l;
          back[i + 1][j + cost[l]] = j;
        }
      }
  int now = n;
  while (dp[now][n] < 0)
    now--;
  int from = n;
  while (now > 0) {
    cout << dp[now][from] + 1;
    from = back[now][from];
    now--;
  }
  cout << endl;
  return 0;
}
