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
  ll x02 = 0;
  for (int i = 0; i < n; i++) if (i % 2 == 0) x02 += a[i]; else x02 -= a[i];
  vector<ll> x(n);
  x[0] = x02 / 2;

  for (int i = 1; i < n; i++)
    x[i] = a[i - 1] - x[i - 1];

  cout << x[0] * 2;
  for (int i = 1; i < n; i++) cout << " " << x[i] * 2;
  cout << endl;
  return 0;
}
