#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;
long long P = 998244353;
set<string> ss;

long long po(long long e, long long x) {
  if (x == 0)
    return 1;
  if (x == 1)
    return e;
  if (x % 2 == 0)
    return po((e * e) % P, x / 2);
  return (e * po(e, x - 1)) % P;
}

int dfs(string &s) {
  if (ss.find(s) != ss.end())
    return 0;
  ss.insert(s);
  long long ret = 1;
  for (int i = 0; i < 2; i++) {
    set<char> c;
    c.insert('a');
    c.insert('b');
    c.insert('c');
    c.erase(s[i]);
    c.erase(s[i + 1]);
    if (c.size() == 1) {
      string t = s;
      t[i] = *c.begin();
      t[i + 1] = *c.begin();
      ret += dfs(t);
    }
  }
  return ret;
}

int main() {
  string s;
  cin >> s;
  bool same = true;
  int n = s.size();
  for (int i = 1; i < n; i++)
    if (s[0] != s[i])
      same = false;
  if (same) {
    cout << 1 << endl;
    return 0;
  }
  if (s.size() == 2) {
    cout << 2 << endl;
    return 0;
  } else if (s.size() == 3) {
    cout << dfs(s) % P << endl;
    return 0;
  }
  bool cont = false;
  for (int i = 1; i < n; i++)
    if (s[i - 1] == s[i])
      cont = true;
  vector<vector<vector<vector<long long>>>> dp(200020);

  for (int i = 0; i <= n; i++) {
    dp[i].resize(2);
    for (int j = 0; j < 2; j++) {
      dp[i][j].resize(3);
      for (int k = 0; k < 3; k++) {
        dp[i][j][k].resize(3);
      }
    }
  }
  dp[1][0][0][0] = 1;
  dp[1][0][1][1] = 1;
  dp[1][0][2][2] = 1;
  for (int i = 1; i < n; i++) {
    for (int mod = 0; mod < 3; mod++) {
      for (int last = 0; last < 3; last++) {
        for (int c = 0; c < 3; c++) {
          if (last != c) {
            dp[i + 1][0][(mod + c) % 3][c] =
                (dp[i + 1][0][(mod + c) % 3][c] + dp[i][0][mod][last]) % P;
          } else {
            dp[i + 1][1][(mod + c) % 3][c] =
                (dp[i + 1][1][(mod + c) % 3][c] + dp[i][0][mod][last]) % P;
          }
          dp[i + 1][1][(mod + c) % 3][c] =
              (dp[i + 1][1][(mod + c) % 3][c] + dp[i][1][mod][last]) % P;
        }
      }
    }
  }
  int mod = 0;
  for (int i = 0; i < n; i++)
    mod = (mod + s[i] - 'a') % 3;
  if (cont) {
    cout << (dp[n][1][mod][0] + dp[n][1][mod][1] + dp[n][1][mod][2]) % P
         << endl;
  } else {
    cout << (dp[n][1][mod][0] + dp[n][1][mod][1] + dp[n][1][mod][2] + 1) % P
         << endl;
  }

  return 0;
}
