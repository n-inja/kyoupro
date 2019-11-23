#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int n;
vector<int> rest;
vector<pair<int, int>> ok;
vector<int> query;
int cnt = 0;

int quest(vector<int> &c) {
  cnt++;
  if (cnt > 210) {
    exit(1);
  }
  if (c.size() != n) {
    exit(1);
  }
  cout << "?";
  for (int i = 0; i < n; i++) cout << " " << c[i];
  cout << endl;
  string q;
  cin >> q;
  if (q == "-1") {
    exit(1);
  }
  return q == "Red";
}

vector<bool> use;

void solve() {
  vector<int> query;
  for (int i = 0; i < n; i++) query.push_back(rest[i]);
  int c = quest(query);
  int l = n, r = rest.size();
  while (r - l > 1) {
    query.clear();
    int m = (r + l) / 2;
    for (int i = m - n; i < m; i++) query.push_back(rest[i]);
    int c2 = quest(query);
    if (c == c2) {
      l = m;
    } else {
      r = m;
    }
  }
  query.clear();
  for (int i = l - n + 1; i < l; i++) query.push_back(rest[i]);
  for (int i = 0; i < l - n; i++) {
    vector<int> q2 = query;
    q2.push_back(rest[i]);
    int c = quest(q2);
    ok.emplace_back(rest[i], c);
    use[rest[i] - 1] = true;
  }
  for (int i = l + 1; i < rest.size(); i++) {
    vector<int> q2 = query;
    q2.push_back(rest[i]);
    int c = quest(q2);
    ok.emplace_back(rest[i], c);
    use[rest[i] - 1] = true;
  }
  ok.emplace_back(rest[l], 1 - c);
  ok.emplace_back(rest[l - n], c);
  use[rest[l] - 1] = true;
  use[rest[l - n] - 1] = true;
  rest.erase(rest.begin() + l);
  rest.erase(rest.begin() + l - n);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n;
  use.resize(2 * n);
  for (int i = 0; i < 2 * n; i++) rest.push_back(i + 1);
  while (ok.size() < n / 2 * 2) {
    solve();
  }
  vector<int> query;
  int c[2] = {0};
  for (int i = 0; i < ok.size(); i++) {
    if (c[ok[i].second] < n / 2) {
      query.push_back(ok[i].first);
      c[ok[i].second]++;
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    if (use[i]) continue;
    vector<int> q2 = query;
    q2.push_back(i + 1);
    int c = quest(q2);
    ok.emplace_back(i + 1, c);
  }
  vector<char> ans(2 * n, '0');
  for (int i = 0; i < ok.size(); i++) {
    ans[ok[i].first - 1] = ok[i].second ? 'R' : 'B';
  }
  int rcnt = 0;
  for (int i = 0; i < 2 * n; i++) if (ans[i] == 'R') rcnt++;
  if (rcnt != n) {
    exit(1);
  }
  cout << "! ";
  for (int i = 0; i < 2 * n; i++) cout << ans[i];
  cout << endl;

  return 0;
}
