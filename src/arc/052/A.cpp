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
  cin >> s;
  string t;
  int n = s.size();
  for (int i = 0; i < n; i++) if (s[i] >= '0' && s[i] <= '9') t.push_back(s[i]);
  cout << t << endl;
  return 0;
}
