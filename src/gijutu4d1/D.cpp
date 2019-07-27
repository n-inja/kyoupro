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
  vector<int> b;
  for (int i = 1; i < n; i++) if (a[i] > a[i - 1])b.push_back(1); else if (a[i] < a[i - 1]) b.push_back(-1);
  if (b.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  int now = 0;
  int ans = 1;
  for (int i = 0; i < b.size(); i++) {
    if (now != b[i]) {
      now = b[i];
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
