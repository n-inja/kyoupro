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
  int v[] = {500, 100, 50, 10, 5, 1};
  int a[6], b;
  cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> b;
  set<ll> s;
  s.insert(0);
  for (int i = 0; i < 6; i++) {
    set<ll> t;
    for (int j = 0; j <= a[i]; j++) {
      for (auto &k : s) t.insert(k + v[i] * j);
    }
    s = t;
  }
  if (s.find(b) == s.end()) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}
