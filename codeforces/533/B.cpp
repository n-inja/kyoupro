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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  map<char, vector<int>> mp;
  char c = s[0];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == c) {
      cnt++;
    } else {
      mp[c].push_back(cnt);
      cnt = 1;
      c = s[i];
    }
  }
  mp[c].push_back(cnt);
  int ans = 0;
  for (auto &p : mp) {
    int sub = 0;
    for (auto &i : p.second) {
      sub += i / k;
    }
    ans = max(ans, sub);
  }
  cout << ans << endl;
  return 0;
}
