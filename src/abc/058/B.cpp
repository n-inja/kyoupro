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
  string s, t;
  cin >> s >> t;
  int n = s.size() + t.size();
  string ans(n, 'a');
  for (int i = 0; i < s.size(); i++) {
    ans[i * 2] = s[i];
  }
  for (int i = 0; i < t.size(); i++) {
    ans[i * 2 + 1] = t[i];
  }
  cout << ans << endl;
  return 0;
}
