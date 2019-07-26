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
  auto eq = [](char c, char d) {
    if (c == '*' || d == '*') return true;
    return c == d;
  };
  bool ok = true;
  int n = s.size();
  for (int i = 0; i < n; i++) if (!eq(s[i], s[n - i - 1])) ok = false;
  if (ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
