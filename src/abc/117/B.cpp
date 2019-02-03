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
  int n, a, b, c;
  string s;
  cin >> n;
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  ll sum = 0;
  for (int i = 0; i < n - 1; i++)
    sum += v[i];
  if (sum > v[n - 1])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
