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
  cin >> n;
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  map<ll, int> mp;
  for (int i = 0; i < n; i++)
    mp[-v[i]]++;
  ll a = -mp.begin()->first;
  ll b = 0;
  for (auto &it : mp) {
    if (a % (-it.first) == 0)
      it.second--;
    if (it.second > 0) {
      b = max(b, -it.first);
    }
  }
  cout << a << " " << b << endl;
  return 0;
}
