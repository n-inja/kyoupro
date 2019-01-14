#include <bits/stdc++.h>

using namespace std;

int main() {
  int unused;
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    long long p = 0, ng = 0;
    for (int j = 0; j < n; j++) {
      if ((j - i) % k == 0)
        continue;
      if (v[j] > 0)
        p++;
      else
        ng++;
    }
    ans = max(ans, max(ng - p, p - ng));
  }
  cout << ans << endl;

  return 0;
}
