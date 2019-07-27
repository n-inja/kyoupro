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
  ll n;
  string x;
  cin >> n >> x;
  for (int i = 2; i <= 10; i++) {
    string t;
    ll m = n;
    while (m) {
      t.push_back((m % i) + '0');
      m /= i;
    }
    reverse(t.begin(), t.end());
    if (t == x) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
