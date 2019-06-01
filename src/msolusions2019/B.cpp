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
  int n = 15 - s.size();
  for (int i = 0; i < s.size(); i++) if (s[i] == 'o') n++;
  if (n >= 8) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
