#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  string s, t;
  cin >> n >> s >> t;
  vll v(n);
  bool r = 0;
  for (int i = n - 1; i >= 0; i--) {
    t[i] -= r;
    r = 0;
    if (t[i] < s[i]) {
      v[i] = (int)t[i] + 26 - s[i];
      r = 1;
    } else {
      v[i] = t[i] - s[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (v[i] % 2 == 1) {
      if (i + 1 < n)
        v[i + 1] += 26;
    }
    v[i] /= 2;
  }
  r = 0;
  for (int i = n - 1; i >= 0; i--) {
    v[i] += r;
    r = 0;
    if (v[i] + s[i] > 'z') {
      s[i] = v[i] + s[i] - 26;
      r = 1;
    } else {
      s[i] += v[i];
    }
  }
  cout << s << endl;
  return 0;
}
