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
  int a, b;
  cin >> a >> b;
  auto f = [](int i) {
    string s = to_string(i);
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
  };
  int ans = 0;
  for (int i = a; i <= b; i++) if (f(i)) ans++;
  cout << ans << endl;
  return 0;
}
