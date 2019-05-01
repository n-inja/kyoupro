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
  vll h(n);
  for (int i = 0; i < n; i++)
    cin >> h[i];
  map<ll, int> mp;
  for (int i = 0; i < n; i++)
    mp[h[i]] = 0;
  int c = 1;
  for (auto &v : mp) {
    v.second = c++;
  }
  for (int i = 0; i < n; i++)
    cout << mp[h[i]] << endl;
  return 0;
}
