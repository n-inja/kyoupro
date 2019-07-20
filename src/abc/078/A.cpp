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
  char x, y;
  cin >> x >> y;
  if (x > y) {
    cout << ">" << endl;
  } else if (x == y) {
    cout << "=" << endl;
  } else {
    cout << "<" << endl;
  }
  return 0;
}
