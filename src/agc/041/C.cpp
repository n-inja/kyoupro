#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

vector<string> b3 = {
  "aab",
  "c.b",
  "cdd",
};

vector<string> b4 = {
  "aabd",
  "ccbd",
  "efgg",
  "efhh",
};

vector<string> b5 = {
  "aab.c",
  "f.b.c",
  "fiijj",
  "ghdd.",
  "gh.ee",
};

vector<string> b6 = {
  "aab...",
  "c.b...",
  "cdd...",
  "...aab",
  "...c.b",
  "...cdd",
};

vector<string> b7 = {
  "aabbcc.",
  "dde...c",
  "f.e...c",
  "fgg...b",
  "...ddeb",
  "...f.ea",
  "...fgga",
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> mp(n);
  string s;
  for (int i = 0; i < n; i++) s.push_back('.');
  for (int i = 0; i < n; i++) mp[i] = s;
  if (n % 3 == 0) {
    for (int i = 0; i < n; i += 3)
      for (int j = 0; j < n; j += 3) {
        mp[i][j] = mp[i][j + 1] = 'a';
        mp[i][j + 2] = mp[i + 1][j + 2] = 'b';
        mp[i + 1][j] = mp[i + 2][j] = 'c';
        mp[i + 2][j + 1] = mp[i + 2][j + 2] = 'd';
      }
    for (int i = 0; i < n; i++) cout << mp[i] << endl;
  } else if (n <= 2) {
    cout << -1 << endl;
  } else if (n == 5) {
    for (int i = 0; i < n; i++) {
      cout << b5[i] << endl;
    }
  } else if (n == 7) {
    for (int i = 0; i < n; i++) {
      cout << b7[i] << endl;
    }
  } else {
    int m = n;
    int oi = 0, oj = 0;
    while (m > 0) {
      if (m % 4 == 3) {
        for (int i = 0; i < 7; i++) {
          for (int j = 0; j < 7; j++) {
            mp[oi + i][oj + j] = b7[i][j];
          }
        }
        oi += 7;
        oj += 7;
        m -= 7;
      } else if (m % 4 == 2 || m % 4 == 1) {
        for (int i = 0; i < 5; i++) {
          for (int j = 0; j < 5; j++) {
            mp[oi + i][oj + j] = b5[i][j];
          }
        }
        oi += 5;
        oj += 5;
        m -= 5;
      } else {
        for (int i = 0; i < 4; i++) {
          for (int j = 0; j < 4; j++) {
            mp[oi + i][oj + j] = b4[i][j];
          }
        }
        oi += 4;
        oj += 4;
        m -= 4;
      }
    }
    for (int i = 0; i < n; i++) cout << mp[i] << endl;
  }
  return 0;
}
