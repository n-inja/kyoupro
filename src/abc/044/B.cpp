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
  map<char, int> mp;
  string s;
  cin >> s;
  for (char &c : s) {
    mp[c]++;
  }
  for (char c = 'a'; c <= 'z'; c++) {
    if (mp[c] % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
