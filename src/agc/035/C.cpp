#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

vector<vector<int>> p;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int k = 1;
  while (k < n) k <<= 1;
  if (k == n) {
    cout << "No" << endl;
    return 0;
  } else if (n == 3) {
    cout << "Yes" << endl;
    cout << "1 2" << endl;
    cout << "2 3" << endl;
    cout << "3 4" << endl;
    cout << "4 5" << endl;
    cout << "5 6" << endl;
    return 0;
  }
  k >>= 1;
  p.resize(n * 2);
  for (int i = 0; i < k - 1; i++) {
    if (i < k - 2) {
      p[i].push_back(i + 1);
      p[i + n].push_back(i + n + 1);
    } else {
      p[i].push_back(n);
    }
  }

  p[k - 1].push_back(n);
  p[k].push_back(k - 1);
  p[k + n].push_back(0);
  p[k - 1 + n].push_back(k + n);
  map<int, int> mp;

  int sum = k;
  for (int i = n; i < k + n - 1; i++) {
    sum = sum ^ (i - n + 1);
    mp[sum] = i;
  }
  sum = (k ^ 1);
  for (int i = k - 2; i >= 0; i--) {
    sum = sum ^ (i + 1);
    mp[sum] = i;
  }
  for (int i = k + 1; i < n; i++) {
    p[i].push_back(k - 1);
    p[i + n].push_back(mp[i + 1]);
  }
  cout << "Yes" << endl;
  for (int i = 0; i < 2 * n; i++) {
    for (auto &t : p[i]) {
      cout << (i + 1) << " " << (t + 1) << endl;
    }
  }

  return 0;
}
