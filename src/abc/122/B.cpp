#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  ll ans = 0;
  ll now = 0;
  bool ok = false;
  s += "$";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A' || s[i] == 'T' || s[i] == 'C' || s[i] == 'G') {
      ok = true;
      now++;
    } else {
      ok = false;
      ans = max(ans, now);
      now = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
