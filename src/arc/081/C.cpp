#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int dp[201010] = {0};
char bdp[201010] = {0};
int bbdp[201010] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int n = s.size();
  vector<int> pos(26, n + 1);
  dp[n] = 1;
  dp[n + 1] = 0;
  bdp[n] = 'a';
  bbdp[n] = n + 1;
  for (int i = n - 1; i >= 0; i--) {
    pos[s[i] - 'a'] = i + 1;
    char small;
    int next = n, index;
    for (int j = 0; j < 26; j++) {
      if (dp[pos[j]] < next) {
        next = dp[pos[j]];
        small = 'a' + j;
        index = pos[j];
      }
    }
    dp[i] = next + 1;
    bdp[i] = small;
    bbdp[i] = index;
  }
  int i = 0;
  while (i <= n) {
    cout << bdp[i];
    i = bbdp[i];
  }
  cout << endl;

  return 0;
}
