#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x, y, z, a, b, c;
  cin >> x >> y >> z >> a >> b >> c;
  if (a < x) {
    cout << "NO" << endl;
    return 0;
  }
  a -= x;
  b += a;
  if (b < y) {
    cout << "NO" << endl;
    return 0;
  }
  b -= y;
  c += b;
  if (c < z) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
