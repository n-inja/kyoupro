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
  int ans = 0;
  string bef(9, ' ');
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 9; j++) {
      if (s[j] == 'o' && bef[j] != 'o') ans++;
      if (s[j] == 'x') ans++;
    }
    bef = s;
  }
  cout << ans << endl;
  return 0;
}
