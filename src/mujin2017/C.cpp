#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int dp[500004][27] = {0};
string s;
int n;
int p[500004][19] = {0};

int dfs(int i, int j, int l) {
  if (dp[i][j] < n + 2) return dp[i][j];
  if (l > 26 || i == n) return dp[i][j] = n + 1;
  if (s[i] == 'a' + j) {
    return dp[i][j] = i + 1;
  } else if (s[i] < 'a' + j) {
    int next = dfs(i, j - 1, l + 1);
    if (next > n) {
      return dp[i][j] = next;
    } else {
      return dp[i][j] = dfs(next, j - 1, 0);
    }
  } else {
    int next = dfs(i, 26, l + 1);
    if (next > n) {
      return dp[i][j] = next;
    } else {
      return dp[i][j] = dfs(next, j, 0);
    }
  }
}

int get(int i, int j) {
  int ret = i;
  int k = 0;
  while (j && ret <= n) {
    if (j % 2) {
      ret = p[ret][k];
    }
    k++;
    j >>= 1;
  }
  return ret;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> s;
  n = s.size();
  s.push_back('a');
  for (int i = 0; i <= n + 2; i++) for (int j = 0; j < 27; j++) dp[i][j] = n + 2;
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j < 27; j++) {
      dfs(i, (s[i] - 'a' + j) % 27, 0);
    }
    p[i][0] = dfs(i, 26, 0);
  }

  for (int k = 0; k < 18; k++) {
    for (int i = 0; i < n + 1; i++) {
      int to = p[i][k];
      if (to <= n)
        p[i][k + 1] = p[to][k];
      else
        p[i][k + 1] = to;
    }
  }

  int q;
  cin >> q;
  int l, r;
  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    l--;
    int x = l;
    int k = 18;
    while (x < r && k >= 0) {
      if (p[x][k] <= r) {
        x = p[x][k];
      } else {
        k--;
      }
    }
    if (x == r) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
