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
  string a, b;
  cin >> a >> b;
  if (a.size() > b.size()) cout << a << endl;
  else cout << b << endl;
  return 0;
}
