#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector <vector<int>>;
using vvl = vector <vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  ll ans = 0;
  for (ll a = 1; a <= n; a++) {
    ll b_num = n / a;
    if (n % a == 0) b_num--;
    ans += b_num;
  }
  cout << ans << endl;
  return 0;
}
