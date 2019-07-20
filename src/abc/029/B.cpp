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
  int n = 12;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    bool ok = false;
    for (auto &c : s) if (c == 'r') ok = true;
    ans += ok;
  }
  cout << ans << endl;
  return 0;
}
