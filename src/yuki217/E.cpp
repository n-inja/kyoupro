#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

vector<vector<int>> p;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  p.resize(n);
  for (int i = 0; i < n; i++) v[i] = i + 1;

  while (v.size() > 1) {
    vector<int> w;
    if (v.size() % 2 == 1) w.push_back(v[v.size() - 1]);
    for (int i = 0; i + 1 < v.size(); i += 2) {
      cout << "? " << v[i] << " " << v[i + 1] << endl;
      int x;
      cin >> x;
      p[v[i] - 1].push_back(v[i + 1] - 1);
      p[v[i + 1] - 1].push_back(v[i] - 1);
      w.push_back(x);
    }
    v = w;
  }
  int fst = v[0];
  v.clear();
  for (auto &i : p[fst - 1]) v.push_back(i + 1);
  while (v.size() > 1) {
    vector<int> w;
    if (v.size() % 2 == 1) w.push_back(v[v.size() - 1]);
    for (int i = 0; i + 1 < v.size(); i += 2) {
      cout << "? " << v[i] << " " << v[i + 1] << endl;
      int x;
      cin >> x;
      p[v[i] - 1].push_back(v[i + 1] - 1);
      p[v[i + 1] - 1].push_back(v[i] - 1);
      w.push_back(x);
    }
    v = w;
  }
  cout << "! " << v[0] << endl;

  return 0;
}
