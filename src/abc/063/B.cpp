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
  for (char c : s) {
    if (mp[c]) {
      cout << "no" << endl;
      return 0;
    }
    mp[c]++;
  }
  cout << "yes" << endl;
  return 0;
}
