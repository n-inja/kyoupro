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
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t;
  string rgb = "RGB";
  int minscore = n + 1;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        if (i == j || j == k || k == i)
          continue;
        int diff = 0;
        string ss;
        for (int l = 0; l < n; l++) {
          if (l % 3 == 0) {
            ss.push_back(rgb[i]);
          } else if (l % 3 == 1) {
            ss.push_back(rgb[j]);
          } else {
            ss.push_back(rgb[k]);
          }
          if (s[l] != ss[l]) {
            diff++;
          }
        }
        if (minscore > diff) {
          minscore = diff;
          t = ss;
        }
      }
  cout << minscore << endl;
  cout << t << endl;
  return 0;
}
