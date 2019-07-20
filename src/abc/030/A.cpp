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
  int a, b, c, d;
  cin >> b >> a >> d >> c;
  if (a * d == c * b) {
    cout << "DRAW" << endl;
  } else if (a * d < c * b) {
    cout << "AOKI" << endl;
  } else {
    cout << "TAKAHASHI" << endl;
  }
  return 0;
}
