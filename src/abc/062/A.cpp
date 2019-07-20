#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

int f(int a) {
  if (a == 2) return 2;
  if (a == 4 || a == 6 || a == 9 || a == 11) return 1;
  return 0;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  int ca = f(a), cb = f(b);
  if (ca == cb) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
