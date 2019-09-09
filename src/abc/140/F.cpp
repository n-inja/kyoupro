#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int m = 1 << n;
  vector<int> s(m);
  multiset<int> now, buf;
  map<int, int> mas;
  int mx = 0;
  for (int i = 0; i < m; i++) {
    cin >> s[i];
    mas[s[i]]++;
    mx = max(s[i], mx);
  }
  sort(s.begin(), s.end());
  if (mas.count(mx) > 1) {
    cout << "No" << endl;
    return 0;
  }
  buf.insert(mx);
  mas.erase(mx);
  for (int i = 0; i < n; i++) {
    for (auto &j : buf) now.insert(j);
    buf.clear();

    for (auto &j : now) {
      auto it = mas.lower_bound(j);
      if (it == mas.begin()) {
        cout << "No" << endl;
        return 0;
      }
      it--;
      buf.insert(it->first);
      it->second--;
      if (it->second == 0)
        mas.erase(it);
    }
  }
  cout << "Yes" << endl;
  return 0;
}
