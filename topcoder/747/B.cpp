#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

struct CycleLength {
  int solve(int seed, int a, int b, int m) {
    vi v(m);
    for (ll i = 0; i < m; i++) {
      v[i] = ((i * a) % m + b) % m;
    }
    vi used(m);
    int now = seed, c = 1, bef = seed;
    while (used[now] == 0) {
      used[now] = c++;
      bef = now;
      now = v[now];
    }
    return used[bef] - used[now] + 1;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  CycleLength c;
  cout << c.solve(1, 7, 0, 1000000) << endl;
  return 0;
}
