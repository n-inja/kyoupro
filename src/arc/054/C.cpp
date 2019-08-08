#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int solve(int n, vector<bitset<200>> &v) {
  for (int k = 0; k < n; k++) {
    for (int i = k; i < n; i++) {
      if (v[i][k]) {
        swap(v[k], v[i]);
        for (int j = k + 1; j < n; j++) {
          if (v[j][k]) {
            v[j] ^= v[k];
          }
        }
        break;
      }
      if (i == n - 1) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<bitset<200>> m(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) m[i][j] = s[j] == '1';
  }
  if (solve(n, m) == 1) {
    cout << "Odd" << endl;
  } else {
    cout << "Even" << endl;
  }


  return 0;
}
