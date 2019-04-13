#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int n;
    cin >> n;
    string s, ans;
    cin >> s;
    vector<bool> wng(n), hng(n);
    int x = 0, y = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == 'E') {
        wng[y] = true;
        x++;
      } else {
        hng[x] = true;
        y++;
      }
    }
    if (s[s.size() - 1] == 'E') {
      for (int j = 0; j < n; j++) {
        if (!wng[j]) {
          for (int k = 0; k < n - 1; k++) {
            ans.push_back('E');
          }
          for (; j < n - 1; j++) {
            ans.push_back('S');
          }
          break;
        }
        ans.push_back('S');
      }
    } else {
      for (int j = 0; j < n; j++) {
        if (!hng[j]) {
          for (int k = 0; k < n - 1; k++) {
            ans.push_back('S');
          }
          for (; j < n - 1; j++) {
            ans.push_back('E');
          }
          break;
        }
        ans.push_back('E');
      }
    }
    cout << "Case #" << i << ": " << ans << endl;
  }
  return 0;
}
