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
  int n, k;
  cin >> n >> k;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  string s;
  cin >> s;
  ll ans = 0;
  vvl scores;
  char c = 0;
  vll v;
  for (int i = 0; i < n; i++) {
    if (c == s[i]) {
      v.push_back(a[i]);
    } else {
      scores.push_back(v);
      v.clear();
      v.push_back(a[i]);
      c = s[i];
    }
  }
  scores.push_back(v);
  for (auto w : scores) {
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    for (int i = 0; i < (k) && i < w.size(); i++) {
      ans += w[i];
    }
  }
  cout << ans << endl;
  return 0;
}
