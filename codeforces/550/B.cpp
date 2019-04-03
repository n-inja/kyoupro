#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vll odd, even;
  for (int i = 0; i < n; i++)
    if (a[i] % 2 == 1)
      odd.push_back(a[i]);
    else
      even.push_back(a[i]);
  if (abs((int)odd.size() - (int)even.size()) <= 1)
    cout << 0 << endl;
  else {
    vll s, t;
    if (odd.size() > even.size()) {
      s = odd;
      t = even;
    } else {
      s = even;
      t = odd;
    }
    sort(s.begin(), s.end());
    ll ans = 0;
    for (int i = 0; i < s.size() - t.size() - 1; i++)
      ans += s[i];
    cout << ans << endl;
  }
  return 0;
}
