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
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 -  i]) ans++;
  }
  cout << ans << endl;
  return 0;
}
