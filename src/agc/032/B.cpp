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
  vector<pair<int, int>> p;
  if (n % 2 == 1) {
    for (int i = 0; i < n - 1; i++)
      p.push_back(make_pair(i, n - 1));
    n--;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (i + j == n - 1)
        continue;
      p.push_back(make_pair(i, j));
    }
  }
  cout << p.size() << endl;
  for (auto &v : p)
    cout << v.first + 1 << " " << v.second + 1 << endl;
  return 0;
}
