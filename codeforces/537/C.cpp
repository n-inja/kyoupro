#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
ll n, k, a, b;
vll v;

// [l, r);
int has(ll l, ll r) {
  auto lit = lower_bound(v.begin(), v.end(), l);
  auto rit = lower_bound(v.begin(), v.end(), r);
  return (rit - lit);
}

ll cost(ll l, ll r) {
  ll num = has(l, r);
  ll len = r - l;
  if (num == 0) {
    return a;
  } else {
    if (len == 1) {
      return b * num;
    }
    return min(b * num * len, cost(l, l + len / 2) + cost(l + len / 2, r));
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> k >> a >> b;
  v.resize(k);
  for (int i = 0; i < k; i++) {
    cin >> v[i];
    v[i]--;
  }
  sort(v.begin(), v.end());
  cout << cost(0, 1LL << n) << endl;
  return 0;
}
