#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int n;

int gcd(int a, int b) {
  if (a == n * 2)
    return b;
  if (b == 1)
    return 1;
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  map<char, string> mp;
  mp['0'] = "0000";
  mp['1'] = "0001";
  mp['2'] = "0010";
  mp['3'] = "0011";
  mp['4'] = "0100";
  mp['5'] = "0101";
  mp['6'] = "0110";
  mp['7'] = "0111";
  mp['8'] = "1000";
  mp['9'] = "1001";
  mp['A'] = "1010";
  mp['B'] = "1011";
  mp['C'] = "1100";
  mp['D'] = "1101";
  mp['E'] = "1110";
  mp['F'] = "1111";
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = n * 2;
  for (int i = 0; i < n; i++) {
    char c = 0;
    int cnt = 0;
    for (int j = 0; j < n / 4; j++) {
      for (int k = 0; k < 4; k++) {
        if (mp[s[i][j]][k] == c) {
          cnt++;
        } else {
          c = mp[s[i][j]][k];
          if (cnt) {
            ans = gcd(ans, cnt);
          }
          if (ans == 1) {
            cout << 1 << endl;
            return 0;
          }
          cnt = 1;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    char c = 0;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (mp[s[j][i / 4]][i % 4] == c) {
        cnt++;
      } else {
        c = mp[s[j][i / 4]][i % 4];
        if (cnt) {
          ans = gcd(ans, cnt);
        }
        if (ans == 1) {
          cout << 1 << endl;
          return 0;
        }

        cnt = 1;
      }
    }
  }

  if (ans == n * 2) {
    cout << n << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
