#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vll b = a;
  map<ll, vector<int>> mp;
  for (int i = 0; i < n; i++)
    mp[-a[i]].push_back(i);
  sort(b.begin(), b.end());
  ll up = b[n - m * k];
  vector<bool> ok(n);
  int cnt = 0;
  ll sum = 0;
  for (auto &it : mp) {
    for (auto &i : it.second) {
      if (cnt < m * k) {
        ok[i] = true;
        sum += a[i];
        cnt++;
      }
    }
  }
  cout << sum << endl;
  vi ans;
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (ok[i])
      cnt++;
    if (cnt >= m) {
      cnt = 0;
      ans.push_back(i + 1);
    }
  }
  cout << ans[0];
  for (int i = 1; i < k - 1; i++)
    cout << " " << ans[i];
  cout << endl;
  return 0;
}
