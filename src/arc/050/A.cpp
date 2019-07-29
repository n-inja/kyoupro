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
  char c, C;
  cin >> C >> c;
  if (C - c == 'A' - 'a') cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
