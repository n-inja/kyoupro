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
  int n;
  cin >> n;
  vll a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  vll c;
  ll sum = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      c.push_back(a[i] - b[i]);
    } else if (a[i] < b[i]) {
      ans++;
      sum += b[i] - a[i];
    }
  }
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());
  int id = 0;
  while (sum > 0 && id < c.size()) {
    sum = max(0ll, sum - c[id]);
    id++;
    ans++;
  }
  if (sum > 0)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
