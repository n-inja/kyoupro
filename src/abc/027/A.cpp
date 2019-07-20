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
  int a, b, c;
  cin >> a >> b >> c;
  map<int, int> d;
  d[a]++;
  d[b]++;
  d[c]++;
  if (d[a] == 3) cout << a << endl;
  else if (d[a] == 1) cout << a << endl;
  else if (d[b] == 1) cout << b << endl;
  else cout << c << endl;
  return 0;
}
