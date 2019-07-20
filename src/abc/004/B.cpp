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
  vector<string> mp(4);
  for (int i = 0; i < 4; i++) getline(cin, mp[i]);
  for (int i = 3; i >= 0; i--) {
    reverse(mp[i].begin(), mp[i].end());
    cout << mp[i] << endl;
  }
  return 0;
}
