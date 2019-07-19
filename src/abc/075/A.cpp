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
  map<int, int> mp;
  int a, b, c;
  cin >> a >> b >> c;
  mp[a]++;
  mp[b]++;
  mp[c]++;
  if (mp[a] == 1) cout << a << endl;
  else if (mp[b] == 1) cout << b << endl;
  else cout << c << endl;
  return 0;
}
