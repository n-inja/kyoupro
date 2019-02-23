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
  int n, m;
  cin >> n >> m;
  vector<pair<int, string>> mp(n);
  for (int i = 0; i < n; i++) {
    mp[i].first = i;
    cin >> mp[i].second;
    for (int j = 0; j < m; j++) {
      if (mp[i].second[j] == '<')
        mp[i].second[j] = '0';
      if (mp[i].second[j] == '=')
        mp[i].second[j] = '1';
      if (mp[i].second[j] == '>')
        mp[i].second[j] = '2';
    }
  }
  sort(mp.begin(), mp.end(),
       [](const pair<int, string> &l, const pair<int, string> &r) {
         return l.second < r.second;
       });
  string now = "";
  vector<bool> used0(n), used1(m);
  for (int i = 0; i < m; i++)
    now.push_back('0');
  vector<vector<pair<int, int>>> ans;
  vector<pair<int, int>> ids;
  bool ok = true;
  for (int i = 0; i < n && ok; i++) {
    if (now == mp[i].second) {
      ids.push_back(make_pair(0, mp[i].first));
    } else {
      for (int j = 0; j < m && ok; j++) {
        if (mp[i].second[j] - now[j] < 0)
          ok = false;
      }
      for (int j = 0; j < m && ok; j++) {
        if (now[j] == '1') {
          if (used1[j])
            ok = false;
          used1[j] = true;
          ids.push_back(make_pair(1, j));
        }
      }
      if (ids.size() > 0)
        ans.push_back(ids);
      ids.clear();
      for (int j = 0; j < m && ok; j++) {
        if (now[j] == '0' && mp[i].second[j] == '2') {
          if (used1[j])
            ok = false;
          used1[j] = true;
          ids.push_back(make_pair(1, j));
        }
      }
      if (ids.size() > 0)
        ans.push_back(ids);
      ids.clear();
      ids.push_back(make_pair(0, mp[i].first));
      now = mp[i].second;
    }
  }
  string end = "";
  for (int i = 0; i < m; i++)
    end.push_back('2');
  if (now == end) {
    ans.push_back(ids);
  } else {
    for (int j = 0; j < m && ok; j++) {
      if (end[j] - now[j] < 0)
        ok = false;
    }
    for (int j = 0; j < m && ok; j++) {
      if (now[j] == '1') {
        if (used1[j])
          ok = false;
        used1[j] = true;
        ids.push_back(make_pair(1, j));
      }
    }
    if (ids.size() > 0)
      ans.push_back(ids);
    ids.clear();
    for (int j = 0; j < m && ok; j++) {
      if (now[j] == '0' && end[j] == '2') {
        if (used1[j])
          ok = false;
        used1[j] = true;
        ids.push_back(make_pair(1, j));
      }
    }
    if (ids.size() > 0)
      ans.push_back(ids);
    ids.clear();
  }
  if (!ok) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    vector<int> ans0(n), ans1(m);
    int c = 1;
    for (auto &v : ans) {
      for (auto &p : v) {
        if (p.first == 0)
          ans0[p.second] = c;
        else
          ans1[p.second] = c;
      }
      c++;
    }
    cout << ans0[0];
    for (int i = 1; i < n; i++)
      cout << " " << ans0[i];
    cout << endl;
    cout << ans1[0];
    for (int i = 1; i < m; i++)
      cout << " " << ans1[i];
    cout << endl;
  }
  return 0;
}
