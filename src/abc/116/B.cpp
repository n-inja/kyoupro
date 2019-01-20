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
  set<int> s;
  s.insert(n);

  int i = 1;
  while (1) {
    i++;
    int ins;
    if (n % 2 == 0) {
      ins = n / 2;
    } else {
      ins = n * 3 + 1;
    }
    if (s.find(ins) == s.end())
      s.insert(ins);
    else {
      cout << i << endl;
      return 0;
    }
    n = ins;
  }
  return 0;
}
