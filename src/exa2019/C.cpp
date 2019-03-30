#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
ll n, q;
string s;
vector<pair<char, char>> ps;

bool fl(int i) {
  if (i == n)
    return false;

  for (int j = 0; j < q; j++) {
    if (ps[j].first == s[i]) {
      if (ps[j].second == 'R')
        i++;
      else
        i--;
    }
    if (i < 0)
      return true;
    if (i >= n)
      return false;
  }
  return false;
}

bool fr(int i) {
  if (i < 0)
    return false;
  for (int j = 0; j < q; j++) {
    if (ps[j].first == s[i]) {
      if (ps[j].second == 'R')
        i++;
      else
        i--;
    }
    if (i < 0)
      return false;
    if (i >= n)
      return true;
  }
  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> q;
  cin >> s;
  ps.resize(q);
  for (int i = 0; i < q; i++) {
    cin >> ps[i].first >> ps[i].second;
  }
  int l = 0, r = n;
  ll ans = 0;
  if (fl(l)) {
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (fl(m)) {
        l = m;
      } else {
        r = m;
      }
    }
    ans = l + 1;
  }
  l = -1;
  r = n - 1;
  if (fr(r)) {
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (fr(m)) {
        r = m;
      } else {
        l = m;
      }
    }
    ans += (n - r);
  }
  cout << n - ans << endl;

  return 0;
}
