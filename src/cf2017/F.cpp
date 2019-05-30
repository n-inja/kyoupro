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
  int k;
  int p;
  cin >> k >> p;
  int n = k * k - k + 1;
  cout << n << " " << k << endl;
  vector<vector<int>> v(n);
  int c = 0;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k - 1; j++) v[i].push_back(c++);
    v[i].push_back(n - 1);
  }
  int d = k;
  for (int i = 0; i < k - 1; i++) {
    for (int j = 0; j < k - 1; j++) {
      int l = j;
      for (int m = 0; m < k - 1; m++) {
        v[d].push_back((k - 1) * m + l);
        l += i * p;
        l %= k - 1;
      }
      v[d].push_back(n - k + i);
      d++;
    }
  }
  for (auto &a : v) {
    cout << a[0] + 1;
    for (int i = 1; i < a.size(); i++) cout << " " << a[i] + 1;
    cout << endl;
  }

  return 0;
}
