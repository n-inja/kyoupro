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
  int a, b, c, x, ans = 0;
  cin >> a >> b >> c >> x;
  for (int i = 0; i <= a; i++)
    for (int j = 0; j <= b; j++)
      for (int k = 0; k <= c; k++)
        if (x == i * 500 + j * 100 + k * 50) ans++;
  cout << ans << endl;
  return 0;
}
