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
  int d = a + b, e = a - b;
  if (c == d && c == e) {
    cout << "?" << endl;
  } else if (c == d) {
    cout << "+" << endl;
  } else if (c == e) {
    cout << "-" << endl;
  } else {
    cout << "!" << endl;
  }
  return 0;
}
