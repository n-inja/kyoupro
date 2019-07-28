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
  vector<int> a;
  for (int i = 1; i < 561010; i++) {
    string s = to_string(i);
    char c = s[0];
    bool all = true;
    for (int j = 0; j < s.size(); j++) if (s[j] != c) all = false;
    if (all) a.push_back(i);
  }
  int n;
  cin >> n;
  cout << a[n - 1] << endl;
  return 0;
}
