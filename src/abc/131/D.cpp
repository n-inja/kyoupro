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
  ll n;
  cin >> n;
  vector<pair<ll, ll>> ps(n);
  for (int i = 0; i < n; i++) cin >> ps[i].first >> ps[i].second;
  sort(ps.begin(), ps.end(), [](const pair<ll, ll> &l, const pair<ll, ll> &r) {
    return l.second < r.second;
  });
  ll now = 0;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    now += ps[i].first;
    if (now > ps[i].second) {
      ok = false;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
