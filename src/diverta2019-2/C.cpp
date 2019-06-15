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
  int n;
  cin >> n;
  vll a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int cnt = 0;
  for (int i = 0; i < n; i++) if (a[i] > 0) cnt++;
  sort(a.begin(), a.end());
  vector<bool> pm(n);

  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= 0) {
      pm[i] = true;
    }
    sum += abs(a[i]);
  }
  if (cnt == 0) {
    pm[n - 1] = false;
    sum += 2 * a[n - 1];
  }
  if (cnt == n) {
    pm[0] = true;
    sum -= 2 * a[0];
  }
  int def = 0;
  for (int i = 0; i < n; i++) if (pm[i]) def = i;
  vector<int> p, m;
  for (int i = 0; i < n; i++) {
    if (i == def) continue;
    if (pm[i]) m.push_back(i);
    else p.push_back(i);
  }

  cout << sum << endl;
  ll now = a[def];
  for (int i = 1; i < p.size(); i++) {
    cout << now << " " << a[p[i]] << endl;
    now -= a[p[i]];
  }
  cout << a[p[0]] << " " << now << endl;
  now = a[p[0]] - now;

  for (int i = 0; i < m.size(); i++) {
    cout << now << " " << a[m[i]] << endl;
    now -= a[m[i]];
  }

  return 0;
}
