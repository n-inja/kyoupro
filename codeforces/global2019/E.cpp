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
  vll v(n), w(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++)
    cin >> w[i];
  vll subv(n - 1), subw(n - 1);
  for (int i = 0; i < n - 1; i++)
    subv[i] = v[i + 1] - v[i];
  for (int i = 0; i < n - 1; i++)
    subw[i] = w[i + 1] - w[i];
  sort(subv.begin(), subv.end());
  sort(subw.begin(), subw.end());
  bool ok = true;
  for (int i = 0; i < n - 1; i++)
    if (subv[i] != subw[i])
      ok = false;
  if (v[0] != w[0] || v[n - 1] != w[n - 1])
    ok = false;
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
