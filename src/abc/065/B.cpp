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
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
  vector<bool> used(n);
  int now = 0;
  int c = 0;
  while (!used[now]) {
    used[now] = true;
    if (now == 1) {
      cout << c << endl;
      return 0;
    }
    c++;
    now = a[now];
  }
  cout << "-1" << endl;
  return 0;
}
