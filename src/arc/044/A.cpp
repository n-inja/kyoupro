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
  cin >> n;
  auto f = [](string s) {
    int ret = 0;
    for (auto &c : s) ret += c - '0';
    return ret;
  };
  if (n == 1) {
    cout << "Not Prime" << endl;
    return 0;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      string s = to_string(n);
      if (f(s) % 3 != 0 && s.back() != '5' && (s.back() - '0') % 2 == 1) {
        cout << "Prime" << endl;
      } else {
        cout << "Not Prime" << endl;
      }
      return 0;
    }
  }
  cout << "Prime" << endl;
  return 0;
}
