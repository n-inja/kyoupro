#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int queryx(int x, int l, int r) {
  if (l == r) {
    return l;
  }
  int m = (l + r) / 2;
  cout << "? " << x << " " << l << " " << x << " " << m << endl;
  int q;
  cin >> q;
  if (q % 2 == 1) {
    return queryx(x, l, m);
  } else {
    return queryx(x, m + 1, r);
  }
}
int queryy(int y, int l, int r) {
  if (l == r) {
    return l;
  }
  int m = (l + r) / 2;
  cout << "? " << l << " " << y << " " << m << " " << y << endl;
  int q;
  cin >> q;
  if (q % 2 == 1) {
    return queryy(y, l, m);
  } else {
    return queryy(y, m + 1, r);
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll wq(n), hq(n);
  bool hok = false, wok = false;
  for (int i = 0; i < n - 1; i++) {
    cout << "? " << i + 1 << " " << 1 << " " << i + 1 << " " << n << endl;
    cin >> wq[i];
    if (wq[i] % 2 == 1)
      wok = true;
  }
  wq[n - 1] = wok ? 1 : 0;
  for (int i = 0; i < n - 1; i++) {
    cout << "? " << 1 << " " << i + 1 << " " << n << " " << i + 1 << endl;
    cin >> hq[i];
    if (hq[i] % 2 == 1)
      hok = true;
  }
  hq[n - 1] = hok ? 1 : 0;
  if (hok && wok) {
    vi xs, ys;
    for (int i = 0; i < n; i++) {
      if (wq[i] % 2 == 1)
        xs.push_back(i + 1);
      if (hq[i] % 2 == 1)
        ys.push_back(i + 1);
    }
    vector<pair<int, int>> ans;
    for (auto &x : xs)
      for (auto &y : ys) {
        cout << "? " << x << " " << y << " " << x << " " << y << endl;
        int q;
        cin >> q;
        if (q == 1)
          ans.emplace_back(x, y);
      }
    if (ans.size() != 2)
      return 1;
    cout << "! " << ans[0].first << " " << ans[0].second << " " << ans[1].first
         << " " << ans[1].second << endl;
  } else {
    if (wok) {
      vi xs;
      for (int i = 0; i < n; i++)
        if (wq[i] % 2 == 1)
          xs.push_back(i + 1);
      if (xs.size() < 2)
        return 0;
      int x1 = xs[0];
      int x2 = xs[1];
      int y1 = queryx(x1, 1, n);
      int y2 = queryx(x2, 1, n);
      cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    } else if (hok) {
      vi ys;
      for (int i = 0; i < n; i++)
        if (hq[i] % 2 == 1)
          ys.push_back(i + 1);
      if (ys.size() < 2)
        return 0;
      int y1 = ys[0];
      int y2 = ys[1];
      int x1 = queryy(y1, 1, n);
      int x2 = queryy(y2, 1, n);
      cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    } else {
    }
  }
  return 0;
}
