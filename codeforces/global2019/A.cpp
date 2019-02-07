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
  int n, k;
  cin >> n >> k;
  vll v(k);
  for (int i = 0; i < k; i++)
    cin >> v[i];
  ll sum = 0;
  ll base = 1;
  for (int i = k - 1; i >= 0; i--) {
    sum += base * v[i];
    sum %= 2;
    base *= n;
    base %= 2;
  }
  if (sum % 2 == 0)
    cout << "even" << endl;
  else
    cout << "odd" << endl;
  return 0;
}
