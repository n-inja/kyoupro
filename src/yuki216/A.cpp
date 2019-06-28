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
  string s1, s2;
  cin >> s1 >> s2;
  if ((s1 == "Sat" || s1 == "Sun") && (s2 == "Sat" || s2 == "Sun")) cout << "8/33" << endl;
  else if (s1 == "Sat" || s1 == "Sun") cout << "8/32" << endl;
  else cout << "8/31" << endl;
  return 0;
}
