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
  if (s[0] >= 'a' && s[0] <= 'z') s[0] = 'A' + s[0] - 'a';
  int n = s.size();
  for (int i = 1; i < n; i++) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = 'a' + s[i] - 'A';
  cout << s << endl;
  return 0;
}
