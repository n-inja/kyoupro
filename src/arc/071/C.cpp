#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

pair<int, int> sum1[101010], sum2[101010];

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  int q;
  cin >> q;
  map<pair<int, int>, int> eq;
  eq[make_pair(0, 0)] = eq[make_pair(1, 1)] = eq[make_pair(2, 2)] = 0;
  eq[make_pair(1, 0)] = eq[make_pair(0, 2)] = eq[make_pair(2, 1)] = 1;
  eq[make_pair(0, 1)] = eq[make_pair(2, 0)] = eq[make_pair(1, 2)] = 2;

  sum2[0] = sum1[0] = make_pair(0, 0);
  for (int i = 0; i < s.size(); i++) {
    sum1[i + 1] = sum1[i];
    if (s[i] == 'A') sum1[i + 1].first++;
    else sum1[i + 1].second++;
  }
  for (int i = 0; i < t.size(); i++) {
    sum2[i + 1] = sum2[i];
    if (t[i] == 'A') sum2[i + 1].first++;
    else sum2[i + 1].second++;
  }
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    c--;
    pair<int, int> v1 = make_pair((sum1[b].first - sum1[a].first) % 3, (sum1[b].second - sum1[a].second) % 3);
    pair<int, int> v2 = make_pair((sum2[d].first - sum2[c].first) % 3, (sum2[d].second - sum2[c].second) % 3);
    if (eq[v1] == eq[v2]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
