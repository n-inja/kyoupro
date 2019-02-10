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
  ll n, b;
  cin >> n >> b;
  map<ll, int> mp;
  for (ll i = 2; i * i <= b; i++) {
    while (b % i == 0) {
      b /= i;
      mp[i]++;
    }
  }
  if (b > 1)
    mp[b]++;
  ll ans = n;
  for (auto &it : mp) {
    ll sum = 0, m = n / it.first;
    while (m) {
      sum += m;
      m /= it.first;
    }
    ans = min(ans, sum / it.second);
  }
  cout << ans << endl;
  return 0;
}
