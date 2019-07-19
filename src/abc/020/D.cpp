#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
ll P = 1000000007;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll LIMIT = 100000;
  vector<bool> is_prime(LIMIT);
  vector<int> prime;
  for (int i = 2; i < LIMIT; i++) {
    if (is_prime[i]) continue;
    prime.push_back(i);
    for (int j = i; j < LIMIT; j += i) is_prime[j] = true;
  }
  ll n, k;
  cin >> n >> k;
  vector<ll> v;
  for (ll i = 1; i * i <= k; i++) {
    if (k % i == 0) {
      v.push_back(i);
      if (k / i != i) v.push_back(k / i);
    }
  }
  ll m = k;
  set<ll> s;
  int i = 0;
  while (m && i < prime.size()) {
    while (m % prime[i] == 0) {
      s.insert(prime[i]);
      m /= prime[i];
    }
    i++;
  }
  if (m > 1) s.insert(m);

  vector<ll> p;
  for (auto &i : s) p.push_back(i);

  auto f = [&](ll n, ll m) {
    ll sum = 0;
    for (int i = 0; i < (1 << p.size()); i++) {
      ll factor = 1;
      int sign = 1;
      for (int j = 0; j < p.size(); j++)
        if ((i >> j) & 1) {
          factor *= p[j];
          sign *= -1;
        }
      if (factor > m || m % factor != 0) continue;
      ll f1 = n / factor + 1;
      ll f2 = n / factor;
      if (f1 % 2 == 0) f1 /= 2;
      else f2 /= 2;
      if (sign == 1) {
        sum += ((f1 * f2) % P * factor) % P;
        sum %= P;
      } else {
        sum += P - ((f1 * f2) % P * factor) % P;
        sum %= P;
      }
    }
    return sum;
  };
  ll ans = 0;
  for (auto &factor : v) {
    ll a = (f(n / factor, k / factor) * k) % P;
    ans += a;
    ans %= P;
  }
  cout << ans << endl;

  return 0;
}
