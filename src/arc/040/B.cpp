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
  int n, r;
  cin >> n >> r;
  string s;
  cin >> s;

  int dist = 0;
  function<int(string &s)> solve;
  solve = [&](string &s) {
    while (s.size() > 0 && s.back() == 'o') {
      s.pop_back();
    }
    if (s.size() == 0) return 0;
    for (int i = 0; i < r && s.size() > 0; i++) s.pop_back();
    dist = max(dist, (int) s.size());
    return solve(s) + 1;
  };

  int ans = solve(s);
  ans += dist;
  cout << ans << endl;
  return 0;
}
