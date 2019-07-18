#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

string fom(int i, int j) {
  string s1 = to_string(i);
  string s2 = to_string(j);
  string s = "0000";
  return s.substr(0, 4 - s1.size()) + s1 + "-" + s.substr(0, 4 - s2.size()) + s2;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> ps(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ps[i].first = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
    ps[i].second = (s[5] - '0') * 1000 + (s[6] - '0') * 100 + (s[7] - '0') * 10 + (s[8] - '0');
    ps[i].first = ps[i].first / 5 * 5;
    ps[i].second = (ps[i].second + 4) / 5 * 5;
  }
  sort(ps.begin(), ps.end());
  vector<bool> rain(3000);
  for (int i = 0; i < n; i++) {
    if (ps[i].first == ps[i].second) continue;
    for (int j = ps[i].first; j < ps[i].second; j++) rain[j] = true;
  }

  vector<int> v;
  for (int i = 0; i <= 24; i++) for (int j = 0; j < 60; j++) v.push_back(i * 100 + j);
  v.push_back(2999);

  int m = v.size();
  vector<pair<int, int>> ans;
  int bef = -1;

  for (int i = 0; i < m; i++) {
    if (rain[v[i]]) {
      if (bef < 0) {
        bef = i;
      }
    } else {
      if (bef >= 0) {
        ans.emplace_back(v[bef], v[i]);
        bef = -1;
      }
    }
  }

  for (auto &pr : ans) {
    cout << fom(pr.first, pr.second) << endl;
  }

  return 0;
}
