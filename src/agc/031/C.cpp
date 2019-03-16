#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

ll ans[260000];
ll n, a, b;

bool solve() {
  ll humming = 0;
  vector<ll> diff, same;
  for (int i = 0; i < n; i++) {
    if ((a >> i) % 2 != (b >> i) % 2) {
      humming++;
      diff.push_back(i);
    } else {
      same.push_back(i);
    }
  }
  if (humming % 2 == 0) {
    cout << "NO" << endl;
    return true;
  }

  ll okbit = 0;
  ll fir = diff[0];
  ans[(1LL << (n - okbit - 1))] = fir;
  okbit += 1;
  for (int i = 1; i < diff.size(); i += 2) {
    ll c = 0;
    ll size = 1LL << (n - okbit);
    for (ll j = 0; j < size * 2; j++) {
      if (j % size == 0)
        continue;
      if (j % (size >> 2) == 0) {
        ans[j] = diff[i + c % 2];
        c++;
      }
    }
    for (ll j = size * 2; j < (1LL << n); j++) {
      if (j % size == 0)
        continue;
      if (j % (size >> 1) == 0) {
        ans[j] = diff[i];
      } else if (j % (size >> 2) == 0) {
        ans[j] = diff[i + 1];
      }
    }
    okbit += 2;
  }
  for (int i = 0; i < same.size(); i++) {
    ll size = 1LL << (n - okbit);
    for (ll j = 0; j < (1LL << n); j++) {
      if (j % size == 0)
        continue;
      if (j % (size >> 1) == 0) {
        ans[j] = same[i];
      }
    }
    okbit++;
  }

  vector<bool> used(1LL << n);
  ans[0] = a;
  used[ans[0]] = true;
  cout << "YES" << endl;
  cout << ans[0];
  for (int i = 1; i < (1LL << n); i++) {
    ans[i] = ans[i - 1] ^ (1LL << (ans[i]));
    used[ans[i]] = true;
    cout << " " << ans[i];
  }
  cout << endl;

  return true;
  if (ans[(1LL << n) - 1] == b) {
    cerr << "same" << endl;
    bool ok = true;
    for (int i = 0; i < (1LL << n); i++)
      if (!used[i])
        ok = false;
    if (!ok) {
      cerr << "ng" << endl;
      return false;
    }
  } else {
    cerr << ans[(1LL << n) - 1] << endl;
    return false;
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> a >> b;

  solve();
  return 0;
}
