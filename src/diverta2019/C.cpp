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
  vector<string> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int sum = 0;
  int a = 0, b = 0, ba = 0;
  for (int i = 0; i < n; i++) {
    if (v[i][0] == 'B') b++;
    if (v[i][v[i].size() - 1] == 'A') a++;
    if (v[i][0] == 'B' && v[i][v[i].size() - 1] == 'A') {
      ba++;
      b--;
      a--;
    }
    for (int j = 0; j < v[i].size() - 1; j++) {
      if (v[i][j] == 'A' && v[i][j + 1] == 'B') sum++;
    }
  }
  if (a) {
    int ans = sum + ba + min(a, b);
    cout << ans << endl;
  } else {
    if (ba) {
      int ans = sum + ba - 1 + min(1, b);
      cout << ans << endl;
    } else {
      cout << sum << endl;
    }
  }
  return 0;
}
