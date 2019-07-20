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
  string num;
  cin >> num;
  cout << "ABC" << string(3, '0').substr(0, 3 - num.size()) << num << endl;
  return 0;
}
