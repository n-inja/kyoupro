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
  string s;
  cin >> s;
  map<char, int> mp;
  mp['O'] = 0;
  mp['D'] = 0;
  mp['I'] = 1;
  mp['Z'] = 2;
  mp['S'] = 5;
  mp['B'] = 8;
  for (char c = '0'; c <= '9'; c++) mp[c] = c - '0';
  for (auto &c : s) cout << mp[c];
  cout << endl;
  return 0;
}
