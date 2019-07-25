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
  set<ll> s;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      s.insert(i);
      s.insert(n / i);
    }
  }
  ll sum = -n;
  for (auto &i : s) sum += i;
  if (sum < n) {
    cout << "Deficient" << endl;
  } else if (sum == n) {
    cout << "Perfect" << endl;
  } else {
    cout << "Abundant" << endl;
  }
  return 0;
}
