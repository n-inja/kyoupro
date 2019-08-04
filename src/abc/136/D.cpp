#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int c[2] = {0};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();

  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      v[i] += c[i % 2];
      v[i - 1] += c[1 - (i % 2)];
      c[0] = c[1] = 0;
    } else {
      c[i % 2]++;
    }
  }

  c[0] = c[1] = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'R') {
      v[i] += c[i % 2];
      v[i + 1] += c[1 - (i % 2)];
      c[0] = c[1] = 0;
    } else {
      c[i % 2]++;
    }
  }

  cout << v[0];
  for (int i = 1; i < n; i++) cout << " " << v[i];
  cout << endl;
  return 0;
}
