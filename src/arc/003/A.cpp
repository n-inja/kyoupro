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
  ll sum = 0;
  for (char &c : s) {
    if (c == 'F') continue;
    sum += 'E' - c;
  }
  printf("%.12lf\n", (double) sum / n);
  return 0;
}
