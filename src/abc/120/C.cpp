#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  string s;
  cin >> s;
  n = s.size();
  vector<int> b;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    b.push_back(s[i] - '0');
    while (b.size() > 1 && b[b.size() - 1] != b[b.size() - 2]) {
      b.pop_back();
      b.pop_back();
      ans += 2;
    }
  }
  cout << ans << endl;
  return 0;
}
