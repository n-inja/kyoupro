#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<ll> l(n);
  for (int i = 0; i < n; i++) cin >> l[i];
  sort(l.rbegin(), l.rend());
  ll sum = 0;
  for (int i = 0; i < k; i++) sum += l[i];
  cout << sum << endl;
  return 0;
}
