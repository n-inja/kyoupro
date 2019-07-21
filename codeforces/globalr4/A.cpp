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
  ll sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  ll ali = a[0];
  vector<int> ans({1});

  for (int i = 1; i < n; i++)
    if (a[i] * 2 <= a[0]) {
      ali += a[i];
      ans.push_back(i + 1);
    }
  if (ali > sum / 2) {
    cout << ans.size() << endl;
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
    cout << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}
