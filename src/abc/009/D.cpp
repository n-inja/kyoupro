#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using mat = vector<vector<ll>>;

void mul(mat &a, mat &b, mat &r) {
  int n = a.size(), m = b[0].size();
  int l = a[0].size();
  if (r.size() != n)
    r.resize(n);

  for (int i = 0; i < n; i++) {
    if (r[i].size() != m)
      r[i].resize(m);
    for (int j = 0; j < m; j++) {
      r[i][j] = 0;
      for (int k = 0; k < l; k++) r[i][j] ^= a[i][k] & b[k][j];
    }
  }
}

int main() {
  ll k, m;
  cin >> k >> m;
  vector<ll> a(k), c(k);
  for (int i = 0; i < k; i++) cin >> a[i];
  for (int i = 0; i < k; i++) cin >> c[i];
  mat A(k, vector<ll>(k));
  ll f = ~0;
  for (int i = 0; i < k - 1; i++) A[i][i + 1] = f;
  for (int i = 0; i < k; i++) A[k - 1][i] = c[k - 1 - i];
  mat I(k, vector<ll>(k)), tmp;
  for (int i = 0; i < k; i++) I[i][i] = f;

  if (m < k) {
    cout << a[m - 1] << endl;
    return 0;
  }
  m -= k;
  while (m) {
    if (m % 2 == 1) {
      mul(A, I, tmp);
      swap(tmp, I);
    }
    mul(A, A, tmp);
    swap(tmp, A);
    m >>= 1;
  }
  mat v(k, vector<ll>(1)), ans;
  for (int i = 0; i < k; i++) v[i][0] = a[i];
  mul(I, v, ans);
  cout << ans[k - 1][0] << endl;

  return 0;
}