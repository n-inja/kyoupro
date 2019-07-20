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
  int l, r;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      l = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'Z') {
      r = i;
      break;
    }
  }
  cout << r - l + 1 << endl;
  return 0;
}
