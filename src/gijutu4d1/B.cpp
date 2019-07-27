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
  ll k;
  cin >> n >> k;
  vector<pair<ll, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a.begin(), a.end());
  auto it = lower_bound(a.begin(), a.end(), make_pair(k, -1));
  if (it == a.begin()) {
    cout << -1 << endl;
  } else {
    it--;
    cout << it->second << endl;
  }
  return 0;
}
