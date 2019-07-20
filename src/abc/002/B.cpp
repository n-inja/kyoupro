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
  string s;
  cin >> s;
  for (auto &c : s) if (c != 'a' && c != 'i' && c != 'u' && c != 'e' && c != 'o') cout << c;
  cout << endl;
  return 0;
}
