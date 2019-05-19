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
  int m, k;
  cin >> m >> k;
  vector<int> b;
  if (m == 0) {
    if (k == 0) {
      cout << "0 0" << endl;
    } else {
      cout << "-1" << endl;
    }
    return 0;
  } else if (m == 1) {
    if (k == 0) {
      cout << "0 0 1 1" << endl;
    } else {
      cout << "-1" << endl;
    }
    return 0;
  }
  ll bit = 1 << m;
  if (k >= bit) {
    cout << -1 << endl;
    return 0;
  }
  b.push_back(k);
  for (int i = 0; i < bit; i++) {
    if (i == k) continue;
    b.push_back(i);
  }
  b.push_back(k);
  for (int i = bit - 1; i >= 0; i--) {
    if (i == k) continue;
    b.push_back(i);
  }
  cout << b[0];
  for (int i = 1; i < bit * 2; i++) cout << " " << b[i];
  cout << endl;
  return 0;
}
