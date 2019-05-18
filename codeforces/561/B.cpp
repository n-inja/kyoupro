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
  int c = 0;
  for (int i = 5; i < n; i++) {
    if (n % i == 0) {
      c = i;
      break;
    }
  }
  if (c == 0) {
    cout << -1 << endl;
    return 0;
  }
  int r = n / c;
  if (r < 5) {
    cout << -1 << endl;
    return 0;
  }
  string vo = "aioue";
  vector<vector<char>> mp(c);
  for (int i = 0; i < c; i++) {
    mp[i].resize(r);
  }
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++) {
      mp[i][j] = vo[i % 5];
    }
  }
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < 5; j++) {
      mp[i][j] = vo[j % 5];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      mp[i][j] = vo[(i - j + 5) % 5];
    }
  }
  for (int i = 0; i < c; i++) for (int j = 0; j < r; j++) cout << mp[i][j];
  cout << endl;

  return 0;
}
