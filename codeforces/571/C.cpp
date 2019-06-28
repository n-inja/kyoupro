#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll sum[101010] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string a, b;
  cin >> a >> b;
  ll ans = 0;
  ll c = 0;
  for (int i = 0; i < b.size(); i++) {
    if (a[i] != b[i]) c++;
  }
  if (c % 2 == 0) ans++;
  for (int i = 0; i < a.size() - b.size(); i++) {
    if (a[i] != a[i + b.size()]) c++;
    if (c % 2 == 0) ans++;
  }
  cout << ans << endl;

  return 0;
}
