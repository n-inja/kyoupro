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
  set<int> s;
  for (int i = 0; i <= 200001; i++) s.insert(i);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    s.erase(p);
    cout << *s.begin() << endl;
  }
  return 0;
}
