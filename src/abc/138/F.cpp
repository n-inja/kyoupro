#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll P = 1000000007;
ll L, R;
ll memo[64][2][2][2] = {0};

ll f(int k, int m, int l, int r) {
  if (k < 0) return m == 1;
  if (memo[k][m][l][r] >= 0) return memo[k][m][l][r];

  ll ret = 0;
  for (int li = 0; li < 2; li++)
    for (int ri = 0; ri < 2; ri++) {
      if (li == 0 && l && (L & (1LL << k)) > 0) continue;
      if (ri == 1 && r && (R & (1LL << k)) == 0) continue;
      if (li > ri) continue;
      if (m == 0 && li != ri) continue;
      ret += f(k - 1, m || (li == 1 && ri == 1), l && ((L >> k) & 1) == li, r && ((R >> k) & 1) == ri);
    }
  return memo[k][m][l][r] = ret % P;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> L >> R;
  for (int i = 0; i < 64; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        for (int l = 0; l < 2; l++)
          memo[i][j][k][l] = -1;


  cout << f(61, 0, 1, 1) << endl;
  return 0;
}
