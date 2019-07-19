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
  int n;
  cin >> n;
  if (n < 60) cout << "Bad" << endl;
  else if (n < 90) cout << "Good" << endl;
  else if (n < 100) cout << "Great" << endl;
  else cout << "Perfect" << endl;
  return 0;
}
