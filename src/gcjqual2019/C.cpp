#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

ll gcd(ll a, ll b) {
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int l = 1; l <= T; l++) {

    ll n, m;
    cin >> n >> m;
    if (n > 1000000)
      continue;
    vll a(m);
    for (int i = 0; i < m; i++)
      cin >> a[i];
    map<ll, int> mp;
    vll primes(m + 1);
    int id = 0;
    for (int i = 0; i < m - 1; i++) {
      if (a[i] != a[i + 1]) {
        ll p = gcd(a[i], a[i + 1]);
        primes[i + 1] = p;
        mp[p] = 0;
        id = i + 1;
        break;
      }
    }
    for (int i = id; i > 0; i--) {
      ll p = a[i - 1] / primes[i];
      primes[i - 1] = p;
      mp[p] = 0;
    }
    for (int i = id; i < m; i++) {
      ll p = a[i] / primes[i];
      primes[i + 1] = p;
      mp[p] = 0;
    }

    int c = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
      mp[it->first] = c++;
    }

    string ans;
    for (auto &p : primes) {
      ans.push_back(mp[p] + 'A');
    }
    cout << "Case #" << l << ": " << ans << endl;
  }
  return 0;
}
