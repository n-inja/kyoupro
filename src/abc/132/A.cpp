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
  sort(s.begin(), s.end());
  if (s[0] == s[1] && s[2] == s[3] && s[1] != s[2])
    cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
