#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

string days[7] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  for (int i = 0; i < 7; i++) {
    if (days[i] == s) {
      if (i == 0 || i == 6) {
        cout << 0 << endl;
      } else {
        cout << 6 - i << endl;
      }
    }
  }

  return 0;
}
