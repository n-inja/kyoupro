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
  char x;
  string s;
  cin >> x >> s;
  for (char c : s) if (c != x) cout << c;
  cout << endl;
  return 0;
}
