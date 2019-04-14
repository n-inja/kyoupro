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
  ll n, m, h;
  cin >> n >> m >> h;
  vll a(m);
  for (int i = 0; i < m; i++)
    cin >> a[i];
  vll b(n);
  for (int i = 0; i < n; i++)
    cin >> b[i];
  vvl mp(n);
  for (int i = 0; i < n; i++) {
    mp[i].resize(m);
    for (int j = 0; j < m; j++)
      cin >> mp[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j]) {
        mp[i][j] = min(a[j], b[i]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << mp[i][0];
    for (int j = 1; j < m; j++)
      cout << " " << mp[i][j];
    cout << endl;
  }
  return 0;
}
