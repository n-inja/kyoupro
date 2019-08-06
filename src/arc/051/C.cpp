#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll P = 1000000007;

ll po(ll e, ll x) {
  ll r = 1;
  while (x) {
    if (x % 2) {
      r = (r * e) % P;
    }
    e = (e * e) % P;
    x >>= 1;
  }
  return r;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll pk[50] = {0};
  pk[0] = 1;

  int n;
  ll a, b;
  cin >> n >> a >> b;
  for (int i = 1; i < 50; i++) {
    pk[i] = pk[i - 1] * a;
  }
  vector<ll> v(n), w;
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  if (a == 1) {
    for (auto &j : v) {
      cout << j << endl;
    }
    return 0;
  }
  ll vmax = *max_element(v.begin(), v.end());
  ll c = 0;
  for (int i = 0; i < n; i++) {
    int j = 0;
    while (v[i] * pk[j] <= vmax) {
      j++;
      c++;
    }
    w.push_back(v[i] * pk[j]);
  }
  if (c > b) {
    priority_queue<ll> q;
    for (int i = 0; i < n; i++) q.push(-v[i]);
    for (int i = 0; i < b; i++) {
      ll now = q.top();
      q.pop();
      q.push(now * a);
    }
    for (int i = 0; i < n; i++) {
      cout << (-q.top()) % P << endl;
      q.pop();
    }
  } else {
    b -= c;
    sort(w.begin(), w.end());
    for (int i = 0; i < n; i++) w[i] %= P;
    ll all = b / n;
    ll st = b % n;
    for (int i = 0; i < n; i++) {
      if (i + st >= n) {
        cout << (w[i + st - n] * po(a, all + 1)) % P << endl;
      } else {
        cout << (w[i + st] * po(a, all)) % P << endl;
      }
    }
  }

  return 0;
}
