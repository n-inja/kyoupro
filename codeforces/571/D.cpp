#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

double eps = 0.0000001;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<double> a(n);
  vector<bool> used(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) if (abs(floor(a[i]) - a[i]) < eps) used[i] = true;

  vector<ll> b(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    b[i] = floor(a[i]);
    sum += b[i];
  }
  for (int i = 0; i < n && sum < 0; i++) {
    if (used[i]) continue;

    b[i] += 1;
    sum += 1;
  }
  for (int i = 0; i < n; i++) cout << b[i] << endl;
  return 0;
}
