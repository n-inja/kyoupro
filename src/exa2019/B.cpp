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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  int r = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R')
      r++;
    else
      b++;
  }
  if (r > b)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
