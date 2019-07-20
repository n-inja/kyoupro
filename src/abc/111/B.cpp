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
  int n;
  cin >> n;
  for (int i = n; i < 10000; i++) {
    string s = to_string(i);
    if (s[0] == s[1] && s[1] == s[2]) {
      cout << s << endl;
      return 0;
    }
  }
  return 0;
}
