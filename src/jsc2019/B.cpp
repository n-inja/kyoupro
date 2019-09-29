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
  int n;
  cin >> n;
  vector<bitset<300>> a(n), b(n), ng(n);
  vector<string> ans(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) if (a[i][j]) ng[n - j - 1] |= ~b[i];
  }
  for (int i = 0; i < n; i++) ng[i] = ~ng[i];
  bool ok = true;
  for (int i = 0; i < n; i++) {
    bitset<300> bs;
    for (int j = 0; j < n; j++) {
      if (a[i][j]) {
        bs |= ng[n - j - 1];
      }
    }
    if (bs != b[i]) ok = false;
  }
  if (!ok) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = n - 1; j >= 0; j--) cout << ng[i][j];
      cout << endl;
    }
  }

  return 0;
}
