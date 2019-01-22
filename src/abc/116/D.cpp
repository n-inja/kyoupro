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
  int n, k;
  cin >> n >> k;
  using pill = pair<int, ll>;
  vector<pill> vp(n);
  for (int i = 0; i < n; i++)
    cin >> vp[i].first >> vp[i].second;
  sort(vp.begin(), vp.end(),
       [](const pill &l, const pill &r) { return l.second > r.second; });
  map<int, vector<ll>> s;
  map<int, ll> mp;
  for (int i = 0; i < n; i++) {
    mp[vp[i].first] = max(mp[vp[i].first], vp[i].second);
  }
  ll ans = 0, score = 0;
  vll v;
  for (int i = 0; i < k; i++) {
    s[vp[i].first].push_back(vp[i].second);
    score += vp[i].second;
  }
  for (auto it : s) {
    sort(it.second.begin(), it.second.end());
    for (int i = 0; i < it.second.size() - 1; i++)
      v.push_back(it.second[i]);
  }
  sort(v.begin(), v.end());
  ans = score + s.size() * s.size();
  multiset<ll> get;
  for (auto &it : mp) {
    if (s.find(it.first) == s.end()) {
      get.insert(-it.second);
    }
  }
  int vid = 0;
  while (get.size() && vid < v.size()) {
    score -= v[vid++];
    score += -*get.begin();
    s[-vid].push_back(-*get.begin());
    get.erase(get.begin());
    ans = max(ans, (ll)(score + s.size() * s.size()));
  }
  cout << ans << endl;
  return 0;
}
