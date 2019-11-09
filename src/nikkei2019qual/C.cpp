#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct N {
  ll a, b;
};

bool operator<(const N &l, const N &r) {
  return l.b > r.b;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n), b(n), aa, bb;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  aa = a;
  bb = b;
  sort(aa.begin(), aa.end());
  sort(bb.begin(), bb.end());
  for (int i = 0; i < n; i++) {
    if (aa[i] > bb[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  for (int i = 1; i < n; i++) {
    if (aa[i - 1] <= bb[i] && aa[i] <= bb[i - 1]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    mp[aa[i]] = bb[i];
  }
  map<ll, int> ainv, binv;
  for (int i = 0; i < n; i++) {
    ainv[a[i]] = i;
    binv[b[i]] = i;
  }

  for (int i = 0; i < n - 1; i++) {
    if (mp[a[i]] == b[i]) {
      cout << "Yes" << endl;
      return 0;
    } else {
      ll tmp = b[i];
      b[i] = mp[a[i]];
      int j = binv[mp[a[i]]];
      b[binv[mp[a[i]]]] = tmp;
      binv[tmp] = j;
    }
  }
  cout << "No" << endl;

  return 0;
}
