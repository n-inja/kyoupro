#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector <vector<int>>;
using vvl = vector <vector<ll>>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  if (s.back() == 's') s.push_back('e');
  s.push_back('s');
  cout << s << endl;
  return 0;
}
