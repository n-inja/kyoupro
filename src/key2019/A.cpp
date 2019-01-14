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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  map<int, bool> mp;
  mp[a] = true;
  mp[b] = true;
  mp[c] = true;
  mp[d] = true;
  if (mp[1] && mp[9] && mp[7] && mp[4])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
