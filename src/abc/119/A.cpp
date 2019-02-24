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
  string s;
  cin >> s;
  int y = stoi(s.substr(0, 4));
  int m = stoi(s.substr(5, 2));
  int d = stoi(s.substr(8, 2));
  if (y < 2019) {
    cout << "Heisei" << endl;
  } else if (y == 2019 && m < 4) {
    cout << "Heisei" << endl;
  } else if (y == 2019 && m == 4 && d <= 30) {
    cout << "Heisei" << endl;
  } else {
    cout << "TBD" << endl;
  }
  return 0;
}
