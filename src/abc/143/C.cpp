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
  string s;
  cin >> n >> s;
  int ans = 1;
  for (int i = 1; i < n; i++) if (s[i - 1] != s[i]) ans++;
  cout << ans << endl;
  return 0;
}
