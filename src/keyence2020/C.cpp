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
  ll n, k, s;
  cin >> n >> k >> s;
  vector<ll> v(n);
  for (int i = 0; i < k; i++) v[i] = s;
  ll next = (s + 1) % 1000000001;
  if (next == 0) next++;
  for (int i = k; i < n; i++) v[i] = next;
  cout << v[0];
  for (int i = 1; i < n; i++) cout << " " << v[i];
  cout << endl;
  return 0;
}
