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
  ll v;
  cin >> v;
  if (v < 100) {
    cout << "00" << endl;
  } else if (v <= 5000) {
    v /= 100;
    if (v < 10) cout << 0 << v << endl;
    else cout << v << endl;
  } else if (v <= 30000) {
    v /= 1000;
    cout << v + 50 << endl;
  } else if (v <= 70000) {
    v /= 1000;
    v -= 30;
    v /= 5;
    v += 80;
    cout << v << endl;
  } else {
    cout << 89 << endl;
  }
  return 0;
}
