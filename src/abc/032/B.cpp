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
  string s;
  int k;
  cin >> s >> k;
  set<string> t;
  if (k > s.size()) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i <= s.size() - k; i++) {
    t.insert(s.substr(i, k));
  }
  cout << t.size() << endl;
  return 0;
}
