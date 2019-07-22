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
  vector<string> s(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (i == n - 1)
      s[i] = s[i].substr(0, s[i].size() - 1);
    if (s[i] == "TAKAHASHIKUN" || s[i] == "Takahashikun" || s[i] == "takahashikun") ans++;
  }
  cout << ans << endl;
  return 0;
}
