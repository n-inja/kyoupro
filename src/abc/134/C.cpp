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
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  auto c = a;
  sort(c.rbegin(), c.rend());
  for (int i = 0; i < n; i++) {
    if (c[0] == a[i]) {
      cout << c[1] << endl;
    } else {
      cout << c[0] << endl;
    }
  }
  return 0;
}
