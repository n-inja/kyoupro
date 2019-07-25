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
  ll a, b;
  cin >> a >> b;
  if (abs(a) < abs(b)) {
    cout << "Ant" << endl;
  } else if (abs(a) == abs(b)) {
    cout << "Draw" << endl;
  } else {
    cout << "Bug" << endl;
  }
  return 0;
}
