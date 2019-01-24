#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  using vpllll = vector<pair<ll, ll>>;
  vpllll vp(m);
  for (int i = 0; i < m; i++) {
    cin >> vp[i].first >> vp[i].second;
    vp[i].first--;
    vp[i].second--;
  }
  ll ans = 0;
  int ansi = -1;
  for (int i = 0; i < n; i++) {
    vll w = v;
    for (int j = 0; j < m; j++) {
      if (vp[j].first <= i && i <= vp[j].second) {
        continue;
      }
      for (int k = vp[j].first; k <= vp[j].second; k++) {
        w[k]--;
      }
    }
    ll minv = w[0];
    for (int i = 1; i < n; i++)
      minv = min(minv, w[i]);
    if (ans < v[i] - minv) {
      ans = v[i] - minv;
      ansi = i;
    }
  }
  cout << ans << endl;
  vector<int> anss;
  for (int i = 0; i < m; i++)
    if (!(vp[i].first <= ansi && ansi <= vp[i].second)) {
      anss.push_back(i + 1);
    }
  cout << anss.size() << endl;
  if (anss.size()) {
    cout << anss[0];
    for (int i = 1; i < anss.size(); i++)
      cout << " " << anss[i];
    cout << endl;
  }
  return 0;
}
