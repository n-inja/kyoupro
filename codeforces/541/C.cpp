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
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  vll ids;
  for (int i = 0; i < n; i += 2)
    ids.push_back(i);
  for (int i = n - 1; i >= 0; i--) {
    if (i % 2 == 1)
      ids.push_back(i);
  }
  cout << a[ids[0]];
  for (int i = 1; i < n; i++)
    cout << " " << a[ids[i]];
  cout << endl;
  return 0;
}
