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
  vector<int> c(5);
  for (int i = 0; i < 5; i++) cin >> c[i];
  vector<ll> v;
  for (int i = 0; i < 5; i++)
    for (int j = i + 1; j < 5; j++)
      for (int k = j + 1; k < 5; k++)
        v.push_back(c[i] + c[j] + c[k]);
  sort(v.rbegin(), v.rend());
  cout << v[2] << endl;
  return 0;
}
