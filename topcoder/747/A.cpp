#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

struct Sherlock {
  string isItHim(string firstName, string lastName) {
    if (firstName.size() < 7 || lastName.size() < 7) {
      return "It is someone else";
    }
    if (firstName[0] != 'B' || lastName[0] != 'C') {
      return "It is someone else";
    }

    int fcnt = 0;
    string s = "BENDICT";
    for (auto &c : firstName) {
      for (auto &c2 : s) {
        if (c2 == c)
          fcnt++;
      }
    }
    int lcnt = 0;
    s = "CUMBERATH";
    for (auto &c : lastName) {
      for (auto &c2 : s) {
        if (c2 == c)
          lcnt++;
      }
    }
    if (fcnt < 3 || lcnt < 5)
      return "It is someone else";
    return "It is him";
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s = "BENDICT";
  sort(s.begin(), s.end());
  cout << s << endl;
  return 0;
}
