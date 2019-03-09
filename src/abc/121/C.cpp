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
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> ab(n);
  for (int i = 0; i < n; i++)
    cin >> ab[i].first >> ab[i].second;
  sort(ab.begin(), ab.end(), [](const pair<ll, ll> &l, const pair<ll, ll> &r) {
    return l.first < r.first;
  });
  ll ans = 0;
  int id = 0;
  while (m > 0) {
    ans += min(m, ab[id].second) * ab[id].first;
    m -= min(m, ab[id].second);
    id++;
  }
  cout << ans << endl;
  return 0;
}
