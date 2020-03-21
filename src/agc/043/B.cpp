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
  int n;
  cin >> n;
  string s, t;
  cin >> s;
  //s.resize(n);
  bool two = false;
  for (int i = 1; i < n; i++) if (abs(s[i] - s[i - 1]) == 2) two = true;
  for (int i = 1; i < n; i++) if (abs(s[i] - s[i - 1]) == 1) two = false;
  bool ok = true;

  vector<bool> bs(n);
  if (two) {
    for (int i = 0; i < n; i++)
      if (s[i] == '3') bs[i] = true;
      else bs[i] = false;
  } else {
    for (int i = 0; i < n; i++)
      if (s[i] == '2') bs[i] = true;
      else bs[i] = false;
  }

  while (bs.size() > 1) {
    int k = 1;
    while (k <= bs.size()) {
      k <<= 1;
    }
    k >>= 1;
    bool c = 0;
    for (int i = 0; i < k - 1; i++) {
      c ^= bs[i];
    }
    vector<bool> cs;
    for (int i = k - 1; i < bs.size(); i++) {
      c ^= bs[i];
      if (i - k >= 0)
        c ^= bs[i - k];
      cs.push_back(c);
    }
    swap(bs, cs);
  }
  ok = bs[0];

  if (two) {
    if (ok)
      cout << 2 << endl;
    else cout << 0 << endl;
  } else {
    if (ok)
      cout << 1 << endl;
    else cout << 0 << endl;
  }
  return 0;
}
