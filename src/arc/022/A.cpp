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
  int j = 0;
  string t = "ICT$", t2 = "ict$";
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == t[j] || s[i] == t2[j]) {
      j++;
    }
  }
  if (j == 3) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
