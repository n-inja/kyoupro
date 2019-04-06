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
  ll n, m;
  cin >> n >> m;
  vvi a(n), b(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(m);
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  }
  for (int i = 0; i < n; i++) {
    b[i].resize(m);
    for (int j = 0; j < m; j++)
      cin >> b[i][j];
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++)
      if (a[i][j] != b[i][j])
        c++;
    if (c % 2 == 1)
      ok = false;
  }
  for (int i = 0; i < m; i++) {
    int c = 0;
    for (int j = 0; j < n; j++)
      if (a[j][i] != b[j][i])
        c++;
    if (c % 2 == 1)
      ok = false;
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
