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
  ll n, k;
  cin >> n >> k;
  vll p;
  ll b = 2;
  while (n > 1) {
    if (n % b == 0) {
      n /= b;
      p.push_back(b);
    } else {
      b++;
    }
    if (b * b > n) {
      p.push_back(n);
      break;
    }
  }
  vll ans;
  if (p.size() > k) {
    for (int i = k; i < p.size(); i++)
      p[k - 1] *= p[i];
  }
  if (p.size() < k) {
    cout << -1 << endl;
  } else {
    cout << p[0];
    for (int i = 1; i < k; i++)
      cout << " " << p[i];
    cout << endl;
  }

  return 0;
}
