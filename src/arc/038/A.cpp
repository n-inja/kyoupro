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
  sort(a.rbegin(), a.rend());
  ll sum0 = 0, sum1 = 0;
  for (int i = 0; i < n; i++) if (i % 2 == 0) sum0 += a[i]; else sum1 += a[i];
  cout << sum0 << endl;
  return 0;
}
