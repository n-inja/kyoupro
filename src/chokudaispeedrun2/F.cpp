#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

ll f(ll a, ll b) {
  return a * 1000000001 + b;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  set<ll> s;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    s.insert(f(min(a, b), max(a, b)));
  }
  cout << s.size() << endl;
  return 0;
}
