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
  int a, b, q;
  cin >> a >> b >> q;
  vll v1(a), v2(b);
  for (int i = 0; i < a; i++)
    cin >> v1[i];
  for (int i = 0; i < b; i++)
    cin >> v2[i];
  v1.push_back(-10000000000000000LL);
  v2.push_back(-10000000000000000LL);
  v1.push_back(10000000000000000LL);
  v2.push_back(10000000000000000LL);
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  for (int i = 0; i < q; i++) {
    ll x;
    cin >> x;
    auto i1 = lower_bound(v1.begin(), v1.end(), x);
    ll r1 = *i1;
    i1--;
    ll l1 = *i1;
    auto i2 = lower_bound(v2.begin(), v2.end(), x);
    ll r2 = *i2;
    i2--;
    ll l2 = *i2;
    if (r1 == x)
      cout << min(r2 - x, x - l2) << endl;
    else if (r2 == x)
      cout << min(r1 - x, x - l1) << endl;
    else
      cout << min(min((x - l1) * 2 + r2 - x, (x - l2) * 2 + r1 - x),
                  min(min((r1 - x) * 2 + (x - l2), (r2 - x) * 2 + (x - l1)),
                      min(max(r2, r1) - x, x - min(l2, l1))))
           << endl;
  }
  return 0;
}
