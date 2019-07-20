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
  for (int i = s.size() / 2 - 1; i > 0; i--) {
    if (s.substr(0, i) == s.substr(i, i)) {
      cout << i * 2 << endl;
      return 0;
    }
  }
  return 0;
}
