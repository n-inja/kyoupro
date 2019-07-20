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
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o' || s[i] == 'k' || s[i] == 'u') {
      continue;
    }
    if (i < n - 1 && s[i] == 'c' && s[i + 1] == 'h') {
      i++;
      continue;
    }
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
