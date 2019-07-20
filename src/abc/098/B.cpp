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
  int n;
  cin >> n >> s;
  auto f = [](string s, string t) {
    int r = 0;
    for (char c = 'a'; c <= 'z'; c++) {
      bool ok1 = false, ok2 = false;
      for (char &d : s) if (c == d) ok1 = true;
      for (char &d : t) if (c == d) ok2 = true;
      if (ok1 && ok2) r++;
    }
    return r;
  };
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    ans = max(ans, f(s.substr(0, i), s.substr(i, s.size())));
  }
  cout << ans << endl;
  return 0;
}
