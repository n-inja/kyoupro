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
  ll id = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == n) id = i;
  }
  int lid = id - 1, rid = id + 1;
  int next = a[id] - 1;
  for (int i = 0; i < n - 1; i++) {
    if (lid >= 0 && a[lid] == next) {
      next--;
      lid--;
      continue;
    }
    if (rid < n && a[rid] == next) {
      next--;
      rid++;
      continue;
    }
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
