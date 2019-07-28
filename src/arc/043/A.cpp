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
  ll a, b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  double diff = v.back() - v[0];
  double q;
  if (v.back() == v[0]) {
    if (b != 0) {
      cout << -1 << endl;
      return 0;
    }
    q = 1;
  } else {
    q = b / diff;
  }
  double sum = 0;
  for (int i = 0; i < n; i++) sum += v[i] * q;
  double mean = sum / (double) n;
  double p = a - mean;
  printf("%.12lf %.12lf\n", q, p);

  return 0;
}
