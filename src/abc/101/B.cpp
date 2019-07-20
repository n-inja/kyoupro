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
  int sum = 0;
  for (char &c : s) sum += c - '0';
  int a = stoi(s);
  if (a % sum == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
