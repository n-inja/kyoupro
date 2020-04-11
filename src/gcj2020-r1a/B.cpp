#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;


ll cmb[500][500] = {0};

int count(ll n) {
  int ret = 0;
  for (int i = 0; i <= 40; i++) {
    if ((n >> i) & 1) ret++;
  }
  return ret;
}

void solve(int t) {
  ll n;
  cin >> n;
  ll sum = 0;
  vector<pair<int, int>> ans;
  pair<int, int> now(1, 1);
  if (n <= 1000) {
    sum = 1;
    ans.push_back(now);
    now = make_pair(2, 2);
    while (sum < n) {
      if (sum + now.first - 1 <= n) {
        ans.push_back(now);
        sum += now.first - 1;
        if (sum == n) {
          now.second -= 1;
          break;
        }
      } else {
        now.first -= 1;
        now.second -= 1;
        break;
      }
      now.first += 1;
    }
    while (sum < n) {
      sum++;
      ans.push_back(now);
      now.first -= 1;
    }
  } else {
    int bit = count(n);
    if (bit == 1) {
      bool right = false;
      while (sum < n) {
        sum += cmb[now.first][now.second];
        ans.push_back(now);
        if (right) {
          if (now.second < now.first) {
            now.second++;
          } else {
            now.first++;
            now.second++;
            right = false;
          }
        } else {
          if (now.second > 1) {
            now.second--;
          } else {
            now.first++;
            right = true;
          }
        }
      }
    } else {
      ll m = n - 50;
      ll mov = 50;
      if (m & 1) {
        m--;
        mov++;
      }
      vector<bool> can(200);
      for (int k = 0; k < 40; k++) {
        if ((m >> k) & 1) can[k] = true;
        cerr << can[k];
      }
      cerr << endl;
      bool right = false;
      while (sum < n) {
        if (now.first < 50)
          sum += cmb[now.first][now.second];
        else sum += 1;
        ans.push_back(now);
        if (!can[now.first - 1]) {
          if (right) {
            now.first++;
          } else {
            now.first++;
            now.second++;
          }
          continue;
        }
        if (right) {
          if (now.second < now.first) {
            now.second++;
          } else {
            now.first++;
            now.second++;
            right = false;
          }
        } else {
          if (now.second > 1) {
            now.second--;
          } else {
            now.first++;
            right = true;
          }
        }
      }
    }
  }
  cout << "Case #" << t << ":" << endl;
  for (auto &pr : ans) {
    cout << pr.first << " " << pr.second << endl;
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cmb[1][1] = 1;
  for (int i = 2; i < 50; i++) {
    for (int j = 1; j <= i; j++) {
      cmb[i][j] = cmb[i - 1][j - 1] + cmb[i - 1][j];
    }
  }
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) solve(i);
  return 0;
}
