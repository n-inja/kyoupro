#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
ll n, q;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> q;
  string s;
  cin >> s;
  vll ac(n + 1);
  for (int i = 1; i < n; i++) {
    ac[i + 1] = ac[i];
    if (s[i] == 'C' && s[i - 1] == 'A') {
      ac[i + 1]++;
    }
  }
  for (int i = 0; i < q; i++) {
    ll l, r;
    cin >> l >> r;
    cout << ac[r] - ac[l] << endl;
  }
  return 0;
}
