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
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  map<ll, ll> bmp, amp;
  for (int i = 0; i < n; i++) {
    bmp[b[i]]++;
  }
  ll bef = n;
  for (int i = 0; i < n; i++) {
    amp[a[i]]++;
    bef = min(bef, bmp[a[i]] / amp[a[i]]);
    cout << bef << endl;
  }
  return 0;
}
