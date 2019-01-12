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
  int a, b;
  cin >> a >> b;
  vi v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int c[3] = {0};
  for (int i = 0; i < n; i++) {
    if (v[i] <= a) {
      c[0]++;
    } else if (v[i] <= b) {
      c[1]++;
    } else {
      c[2]++;
    }
  }
  cout << min(min(c[0], c[1]), c[2]) << endl;
  return 0;
}
