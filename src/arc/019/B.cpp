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
  string t;
  t = s;
  reverse(t.begin(), t.end());
  int n = s.size();
  int c = 0;
  for (int i = 0; i < n; i++)if (s[i] == t[i]) c++;
  if (c == n) {
    if (n % 2 == 1) {
      cout << 25 * (n - 1) << endl;
    } else {
      cout << 25 * n << endl;
    }
  } else if (n == c + 2) {
    cout << 25 * (n - 2) + 24 * 2 << endl;
  } else {
    cout << 25 * n << endl;
  }
  return 0;
}
