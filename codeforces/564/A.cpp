#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n;
vector<int> a, b;

ll g(int k) {
  vector<bool> ok(n);
  int score = k;
  for (int i = 0; i < n; i++) if (a[i]) ok[a[i] - 1] = true;
  for (int i = 0; i < k; i++) if (b[i]) ok[b[i] - 1] = true;
  int p = k;
  for (int i = 0; i < n; i++) {
    if (!ok[i]) return score;
    if (p < n) if (b[p]) ok[b[p] - 1] = true;
    p++;
    score++;
  }
  return score;
}

ll f(int k) {
  vector<bool> ok(n);
  for (int i = 0; i < n; i++) if (a[i]) ok[a[i] - 1] = true;
  for (int i = 0; i < k; i++) if (b[i]) ok[b[i] - 1] = true;
  int p = k;
  for (int i = 0; i < n; i++) {
    if (!ok[i]) return false;
    if (p < n) if (b[p]) ok[b[p] - 1] = true;
    p++;
  }
  return true;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  {
    auto c = b;
    set<int> s;
    vector<bool> used(n);
    for (int i = 0; i < n; i++) if (a[i] > 0) s.insert(a[i]);
    int k = 0, score = 0;
    while (s.size() && (k < c.size() && c[k] != 1)) {
      if (used[*s.begin() - 1]) {
        k = 0;
        c[k] = -1;
        break;
      }
      used[*s.begin() - 1] = true;
      c.push_back(*s.begin());
      s.erase(s.begin());

      if (c[k] > 0) {
        s.insert(c[k]);
      }

      k++;
      score++;
    }

    if (c[k] == 1) {
      int cnt = 1;
      for (k = k + 1; k < c.size(); k++) {
        if (c[k] - c[k - 1] == 1) cnt++;
      }
      if (cnt == n) {
        cout << score << endl;
        return 0;
      }
    }
  }

  ll l = 0, r = n;
  while (r - l > 1) {
    ll m = (r + l) / 2;
    if (f(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << g(r) << endl;

  return 0;
}
