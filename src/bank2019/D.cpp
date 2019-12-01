#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

bool dp1[10] = {0};
bool dp2[10][10] = {0};
bool dp3[10][10][10] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  int n;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) if (dp2[j][k]) dp3[j][k][s[i] - '0'] = true;
    }
    for (int j = 0; j < 10; j++) if (dp1[j]) dp2[j][s[i] - '0'] = true;
    dp1[s[i] - '0'] = true;
  }
  int ans = 0;
  for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) for (int k = 0; k < 10; k++) ans += dp3[i][j][k];
  cout << ans << endl;
  return 0;
}
