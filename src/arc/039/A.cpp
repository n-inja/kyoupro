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
  int ans = -100000;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 10; j++) {
      if (i == 0 && j == 0) continue;
      char c = s[i];
      s[i] = '0' + j;
      ans = max(ans, stoi(s) - stoi(t));
      s[i] = c;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 10; j++) {
      if (i == 0 && j == 0) continue;
      char c = t[i];
      t[i] = '0' + j;
      ans = max(ans, stoi(s) - stoi(t));
      t[i] = c;
    }
  }
  cout << ans << endl;
  return 0;
}
