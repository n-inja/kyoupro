#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
struct N {
  int t, i, j;
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  map<ll, int> mp;
  ll num = 0, cnt = 0;
  int id = 0;
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
    if (cnt < mp[a[i]]) {
      cnt = mp[a[i]];
      num = a[i];
      id = i;
    }
  }
  vector<N> ans;
  for (int i = id - 1; i >= 0; i--) {
    if (a[i] == num)
      continue;
    if (a[i] > num) {
      ans.push_back(N{2, i, i + 1});
    } else {
      ans.push_back(N{1, i, i + 1});
    }
  }
  for (int i = id + 1; i < n; i++) {
    if (a[i] == num)
      continue;
    if (a[i] > num) {
      ans.push_back(N{2, i, i - 1});
    } else {
      ans.push_back(N{1, i, i - 1});
    }
  }
  cout << ans.size() << endl;
  for (auto &b : ans)
    cout << b.t << " " << b.i + 1 << " " << b.j + 1 << endl;
  return 0;
}
