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
  vector<ll> b(n);
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<ll> a(n);
  for (int i = 0; i < n - 1; i++) a[i + 1] = a[i] ^ b[i];
  if ((b.back() ^ a.back()) != 0) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n; i++) cout << a[i] << endl;
  }
  return 0;
}
