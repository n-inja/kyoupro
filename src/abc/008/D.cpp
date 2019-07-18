#include <bits/stdc++.h>

using namespace std;
int n, h, w;
vector<pair<int, int>> ps;
map<pair<pair<int, int>, pair<int, int>>, int> memo;

int dfs(int i, int j, int k, int l) {
  if (memo.find(make_pair(make_pair(i, j), make_pair(k, l))) != memo.end())
    return memo[make_pair(make_pair(i, j), make_pair(k, l))];
  int ans = 0;
  for (auto &v : ps) {
    if (i <= v.first && v.first < k && j <= v.second && v.second < l) {
      ans = max(ans, (k - i) + (l - j) - 1 + dfs(i, j, v.first, v.second) + dfs(v.first + 1, j, k, v.second) +
                     dfs(i, v.second + 1, v.first, l) + dfs(v.first + 1, v.second + 1, k, l));
    }
  }
  return memo[make_pair(make_pair(i, j), make_pair(k, l))] = ans;
}

int main() {
  cin >> w >> h >> n;
  ps.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> ps[i].first >> ps[i].second;
    ps[i].first--;
    ps[i].second--;
  }
  cout << dfs(0, 0, w, h) << endl;
  return 0;
}