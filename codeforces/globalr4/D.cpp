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
  vector<int> primes;
  int lim = 101010;
  vector<bool> used(lim);
  for (int i = 2; i < lim; i++) {
    if (!used[i]) {
      primes.push_back(i);
      for (int j = i; j < lim; j += i) used[j] = true;
    }
  }
  int n;
  cin >> n;
  auto it = lower_bound(primes.begin(), primes.end(), n);
  vector<vector<int>> p(n);
  int edge = *it;
  vector<pair<int, int>> ps;
  for (int i = 0; i < n; i++) {
    int next = (i + 1) % n;
    ps.emplace_back(i + 1, next + 1);
  }

  if (n == 4) {
    cout << 5 << endl;
    cout << "1 2" << endl;
    cout << "1 3" << endl;
    cout << "2 3" << endl;
    cout << "2 4" << endl;
    cout << "3 4" << endl;
    return 0;
  }

  int rest = edge - n;
  vector<int> odd, even;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) even.push_back(i + 1);
    else odd.push_back(i + 1);
  }
  for (int i = 0; i < rest; i++) {
    ps.emplace_back(even[i], odd[(i + 1) % odd.size()]);
  }
  cout << ps.size() << endl;
  for (auto &v : ps) {
    cout << v.first << " " << v.second << endl;
  }

  return 0;
}
