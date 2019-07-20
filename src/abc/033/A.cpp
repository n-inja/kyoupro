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
  if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3]) {
    cout << "SAME" << endl;
  } else {
    cout << "DIFFERENT" << endl;
  }
  return 0;
}
