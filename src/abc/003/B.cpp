#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

bool contains(char c) {
  string t = "atcoder@";
  for (int i = 0; i < t.size(); i++)if (c == t[i]) return true;
  return false;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  bool ok = true;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      if (s[i] == '@' && contains(t[i])) continue;
      if (t[i] == '@' && contains(s[i])) continue;
      ok = false;
    }
  }
  if (ok) {
    cout << "You can win" << endl;
  } else {
    cout << "You will lose" << endl;
  }
  return 0;
}
