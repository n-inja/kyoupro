#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll bitgauss(vector<ll> &a) {
  ll r = 0;
  int n = a.size();
  int rank = 0;
  for (int k = 60; k >= 0; k--) {
    for (int i = rank; i < n; i++) {
      if (a[i] & (1LL << k)) {
        swap(a[rank], a[i]);
        r |= (1LL << k);
        for (int j = 0; j < n; j++) {
          if (j == rank) continue;
          if (a[j] & (1LL << k)) {
            a[j] ^= a[rank];
          }
        }
        rank++;
        break;
      }
    }
  }
  return r;
}

int msb(ll bit) {
  for (int k = 60; k >= 0; k--) {
    if (bit & (1LL << k)) return k;
  }
  return -1;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<int> count(61);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 60; j++) {
      if (a[i] & (1LL << j)) count[j]++;
    }
  }
  ll A = 0;
  for (int i = 0; i < n; i++) {
    A ^= a[i];
  }

  ll mask = 0;
  for (int i = 0; i <= 60; i++) {
    if (count[i] % 2 == 0 && count[i] > 0) mask |= (1LL << i);
  }
  for (int i = 0; i < n; i++) {
    a[i] &= mask;
  }
  bitgauss(a);
  ll B = 0;
  for (int i = 0; i < n; i++) {
    ll m = msb(a[i]);
    if (m >= 0 && count[m] % 2 == 0) {
      B ^= a[i];
      for (int k = 0; k <= 60; k++) {
        if (a[i] & (1LL << k)) count[k]++;
      }
    }
  }
  cout << (A ^ B) + B << endl;
  return 0;
}
