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
  cin >> s >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    string t = s.substr(a, b - a);
    reverse(t.begin(), t.end());
    s = s.substr(0, a) + t + s.substr(b, s.size());
  }
  cout << s << endl;
  return 0;
}
