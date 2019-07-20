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
  string s;
  cin >> n >> s;
  string t = "b";
  int i = 0;
  while (s.size() > t.size()) {
    i++;
    if (i % 3 == 1) {
      t = "a" + t + "c";
    } else if (i % 3 == 2) {
      t = "c" + t + "a";
    } else {
      t = "b" + t + "b";
    }
  }
  if (s == t) {
    cout << i << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
