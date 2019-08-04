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
  vector<ll> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];
  bool ok = true;
  int bef = 0;
  for (int i = 0; i < n; i++) {
    if (h[i] > bef) {
      h[i]--;
    }
    if (bef > h[i]) ok = false;
    bef = h[i];
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
