#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

ll P = 1000000007;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<ll> c(1 << 26);
  ll n;
  string s;
  cin >> n >> s;

  for (int i = 0; i < n; i++) {
    c[s[i] - 'a']++;
  }
  ll ans = 1;
  for (int i = 0; i < 26; i++) {
    ans *= (c[i] + 1);
    ans %= P;
  }
  ans += P - 1;
  ans %= P;
  cout << ans << endl;

  return 0;
}
