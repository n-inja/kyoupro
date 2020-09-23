#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector <vector<int>>;
using vvl = vector <vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> d(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> d[i];
  }
  bool ok = false;
  for (int i = 2; i < n; i++)
    if (d[i * 2 - 4] == d[i * 2 - 3] && d[i * 2 - 2] == d[i * 2 - 1] && d[i * 2] == d[i * 2 + 1])ok = true;
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
