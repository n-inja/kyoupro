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
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(q);
  for (int i = 0; i < q; i++) cin >> a[i];
  vector<ll> score(n, k - q);
  for (int i = 0; i < q; i++) score[a[i] - 1]++;
  for (int i = 0; i < n; i++) {
    if (score[i] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
