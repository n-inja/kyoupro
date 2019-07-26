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
  int n, a, b;
  cin >> n >> a >> b;
  n %= a + b;
  if (n == 0) cout << "Bug" << endl;
  else if (n <= a) cout << "Ant" << endl;
  else cout << "Bug" << endl;
  return 0;
}
