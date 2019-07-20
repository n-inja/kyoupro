#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> ori(n), sma(m);
  for (int i = 0; i < n; i++) cin >> ori[i];
  for (int i = 0; i < m; i++) cin >> sma[i];
  for (int i = 0; i <= n - m; i++)
    for (int j = 0; j <= n - m; j++) {
      bool ok = true;
      for (int k = 0; k < m; k++)
        for (int l = 0; l < m; l++) {
          if (ori[i + k][j + l] != sma[k][l]) ok = false;
        }
      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  cout << "No" << endl;
  return 0;
}
