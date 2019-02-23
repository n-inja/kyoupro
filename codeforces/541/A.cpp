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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (a + 2) + b * 2 + (c + 2) + d * 2 + (a - c) << endl;
  return 0;
}
