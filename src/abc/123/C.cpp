#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  vll a(5);
  ll n;
  cin >> n;
  for (int i = 0; i < 5; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  cout << 4 + ((n + a[0] - 1) / a[0]) << endl;
  return 0;
}
