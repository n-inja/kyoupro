#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int m;
  ll k;
  cin >> m >> k;
  vll a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
  }
  vll A(n - 1);
  for (int i = 0; i < n - 1; i++)
    A[i] = i;
  for (int i = 0; i < m; i++)
    swap(A[a[i] - 1], A[a[i]]);
  vll C(n - 1), B(n - 1);
  for (int i = 0; i < n - 1; i++)
    C[i] = B[i] = i;
  while (k) {
    if (k & 1) {
      C = B;
      for (int i = 0; i < n - 1; i++)
        B[i] = A[C[i]];
    }
    for (int i = 0; i < n - 1; i++)
      C[i] = A[A[i]];
    A = C;
    k >>= 1;
  }
  vll diff(n - 1);
  for (int i = 0; i < n - 1; i++)
    diff[i] = v[i + 1] - v[i];
  vll ans(n);
  ans[0] = v[0];
  for (int i = 0; i < n - 1; i++) {
    ans[i + 1] = ans[i] + diff[B[i]];
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << endl;

  return 0;
}
