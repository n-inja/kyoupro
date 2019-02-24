#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

ll gcd(ll a, ll b) {
  if (a % b == 0)
    return b;
  return gcd(b, a % b);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll g = a[0];
  for (int i = 1; i < n; i++)
    g = gcd(g, a[i]);
  cout << g << endl;
  return 0;
}
