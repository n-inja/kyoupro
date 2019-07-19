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
  for (auto &c : s) mp[c]++;
  cout << mp['A'] << " " << mp['B'] << " " << mp['C'] << " " << mp['D'] << " " << mp['E'] << " " << mp['F'] << endl;
  return 0;
}
