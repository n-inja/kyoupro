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
  int n, a, b, c, d;
  string s;

  cin >> n >> a >> b >> c >> d >> s;
  s.push_back('$');
  s.push_back('$');
  s.push_back('$');
  bool ok = false;
  a--;
  b--;
  c--;
  d--;
  for (int i = max(b - 1, 0); i <= d - 1; i++) {
    if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') ok = true;
  }
  bool ac = true;
  bool bd = true;
  for (int i = a; i < c; i++) {
    if (s[i] == '#' && s[i + 1] == '#') ac = false;
  }
  for (int i = b; i < d; i++) {
    if (s[i] == '#' && s[i + 1] == '#') bd = false;
  }
  if (ac && bd) {
    if (c < d) {
      cout << "Yes" << endl;
    } else {
      if (ok) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  } else {
    cout << "No" << endl;
  }

  return 0;
}
