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
  int n, k;
  cin >> n >> k;
  cin >> s;
  s[k - 1] += 'a' - 'A';
  cout << s << endl;
  return 0;
}
