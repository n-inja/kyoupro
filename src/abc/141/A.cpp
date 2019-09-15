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
  string s;
  cin >> s;
  if (s == "Sunny") cout << "Cloudy";
  else if (s == "Cloudy") cout << "Rainy";
  else cout << "Sunny";
  cout << endl;
  return 0;
}
