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
  string s;
  cin >> s;
  bool ok = false;
  int n = s.size();
  for (int l = 0; l < n; l++) {
    for (int r = 0; r <= n - l; r++) {
      if (s.substr(0, l) + s.substr(l + r, n) == "keyence")
        ok = true;
    }
  }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
