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
  ll n, t;
  cin >> n >> t;
  vector<pair<ll, ll>> ps(n);
  for (int i = 0; i < n; i++) {
    cin >> ps[i].first >> ps[i].second;
  }
  vector<pair<ll, ll>> q;
  for (int i = 0; i < n; i++) {
    if (t < ps[i].first)
      q.emplace_back(i, ps[i].first);
    else
      q.emplace_back(i, ps[i].first + ((t - ps[i].first) + ps[i].second - 1) /
                                          ps[i].second * ps[i].second);
  }
  sort(q.begin(), q.end(), [](const pair<ll, ll> &l, const pair<ll, ll> &r) {
    return l.second < r.second;
  });
  cout << q[0].first + 1 << endl;
  return 0;
}
