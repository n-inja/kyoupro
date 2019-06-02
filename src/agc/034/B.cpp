#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector <vector<int>>;
using vvl = vector <vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  vector<int> v;
  int n = s.size();
  s.push_back('$');
  int c = 0, now = '-';
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (now == 'A') {
      if (s[i] == 'A') {
        c++;
      } else if (s[i] == 'B' && s[i + 1] == 'C') {
        ans += c;
        now = 'A';
        i++;
      } else {
        c = 0;
        now = '-';
      }
    } else {
      if (s[i] == 'A') {
        c = 1;
        now = 'A';
      }
    }
  }
  cout << ans << endl;
  return 0;
}
