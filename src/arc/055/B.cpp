#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

double memo[1010][1010][2] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) for (int b = 0; b < 2; b++) memo[i][j][b] = -1;

  function<double(int, int, int)> dfs;
  dfs = [&](int i, int j, int b) {
    if (i == n) return (double) b;
    if (memo[i][j][b] >= 0) return memo[i][j][b];
    memo[i][j][b] = 1. * i / (i + 1) * dfs(i + 1, j, b);
    double ad = 0.;
    if (j < k) ad = 1. / (i + 1) * dfs(i + 1, j + 1, 1);
    ad = max(ad, 1. / (i + 1) * dfs(i + 1, j, 0));
    memo[i][j][b] += ad;
    return memo[i][j][b];
  };

  printf("%.12lf\n", dfs(0, 0, 0));

  return 0;
}
