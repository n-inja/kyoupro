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
  string s(n, 'a');
  set<string> ans;
  while (ans.find(s) == ans.end()) {
    ans.insert(s);
    int i = 0;
    while (i < n && s[i] == 'c') i++;
    for (int j = 0; j < i; j++) s[j] = 'a';
    if (i < n)
      s[i]++;
  }
  for (auto &s : ans) cout << s << endl;
  return 0;
}
