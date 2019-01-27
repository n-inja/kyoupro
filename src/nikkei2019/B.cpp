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
  string a, b, c;
  cin >> n >> a >> b >> c;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    set<char> s;
    s.insert(a[i]);
    s.insert(b[i]);
    s.insert(c[i]);
    if (s.size() == 2)
      ans++;
    else if (s.size() == 3)
      ans += 2;
  }
  cout << ans << endl;
  return 0;
}
