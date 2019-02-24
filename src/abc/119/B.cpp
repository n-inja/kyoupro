#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  double sum = 0;
  for (int i = 0; i < n; i++) {
    string s;
    double x;
    cin >> x >> s;
    if (s == "JPY")
      sum += x;
    else
      sum += 380000 * x;
  }
  printf("%.9lf\n", sum);
  return 0;
}
