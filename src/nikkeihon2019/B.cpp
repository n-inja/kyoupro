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
  int n, m;
  ll k;
  cin >> n >> m >> k;
  vll a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];
  if (n > m)
    cout << "Y" << endl;
  else if (m > n)
    cout << "X" << endl;
  else {
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i])
        ;
      if (a[i] < b[i]) {
        cout << "X" << endl;
        return 0;
      }
      if (a[i] > b[i]) {
        cout << "Y" << endl;
        return 0;
      }
    }
    cout << "Same" << endl;
  }
  return 0;
}
