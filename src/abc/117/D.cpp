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
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  vll biton(60), bitoff(60);
  for (int k = 0; k < 60; k++) {
    for (int i = 0; i < n; i++) {
      if ((v[i] >> k) & 1) {
        bitoff[k] += 1LL << k;
      } else {
        biton[k] += 1LL << k;
      }
    }
  }
  int k = 0;
  ll m2 = m;
  while (m2) {
    k++;
    m2 >>= 1;
  }

  ll ans = 0;
  ll now = 0;
  for (int i = 0; i < 60; i++) {
    now += bitoff[i];
  }
  ans = now;
  vll maxb(61);
  for (int i = 0; i < 60; i++) {
    maxb[i + 1] = maxb[i] + max(biton[i], bitoff[i]);
  }
  now = 0;
  for (int i = 60; i >= 0; i--) {
    if ((m >> i) & 1) {
      now += biton[i];
      ans = max(ans, now - biton[i] + bitoff[i] + maxb[i]);
    } else {
      now += bitoff[i];
    }
  }
  ans = max(ans, now);
  cout << ans << endl;
  return 0;
}
