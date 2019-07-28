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
  map<pair<int, int>, int> mp;
  vector<pair<int, int>> ps(n);
  vector<int> r;
  for (int i = 0; i < n; i++) {
    cin >> ps[i].first >> ps[i].second;
    ps[i].second--;
    r.push_back(ps[i].first);
    mp[ps[i]]++;
  }
  sort(r.begin(), r.end());
  for (int i = 0; i < n; i++) {
    ll win = lower_bound(r.begin(), r.end(), ps[i].first) - r.begin();
    win += mp[make_pair(ps[i].first, (ps[i].second + 1) % 3)];
    ll lose = r.end() - upper_bound(r.begin(), r.end(), ps[i].first);
    lose += mp[make_pair(ps[i].first, (ps[i].second + 2) % 3)];
    ll draw = n - 1 - win - lose;
    cout << win << " " << lose << " " << draw << endl;
  }


  return 0;
}
