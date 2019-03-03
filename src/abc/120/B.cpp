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
  ll a, b, k;
  cin >> a >> b >> k;
  ll c = 0;
  vll ans;
  for (int i = 1; i <= 100; i++) {
    if (a % i == 0 && b % i == 0) {
      c++;
      ans.push_back(i);
    }
  }
  cout << ans[ans.size() - k] << endl;
  return 0;
}
