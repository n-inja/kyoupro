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
  bool ok = false;
  for (int i = 1; i < s.size(); i++) if (s[i - 1] == s[i]) ok = true;
  if (ok) cout << "Bad" << endl;
  else cout << "Good" << endl;
  return 0;
}
