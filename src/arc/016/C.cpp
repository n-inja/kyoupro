#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

double dp[1 << 10] = {0};

vector<ll> cost;
vector<vector<int>> idle;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  cost.resize(m);
  idle.resize(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    int c;
    cin >> c >> cost[i];
    for (int j = 0; j < c; j++) {
      int id;
      cin >> id;
      id--;
      cin >> idle[i][id];
    }
  }

  double INF = 1010101010;
  function<double(int)> dfs;
  dp[0] = 0.;
  for (int i = 1; i < (1 << n); i++) dp[i] = INF;
  dfs = [&](int bit) {
    if (dp[bit] < INF) return dp[bit];
    for (int j = 0; j < m; j++) {
      double change = 0., sum = 0.;
      for (int i = 0; i < n; i++) {
        if ((bit >> i) & 1) change += idle[j][i] / 100.;
      }
      for (int i = 0; i < n; i++) {
        if ((bit >> i) & 1) sum += idle[j][i] / 100. / change * dfs(bit ^ (1 << i));
      }
      dp[bit] = min(dp[bit], cost[j] / change + sum);
    }
    return dp[bit];
  };
  dfs((1 << n) - 1);

  printf("%.12lf\n", dp[(1 << n) - 1]);
  return 0;
}
