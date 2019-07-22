#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

using tiii = tuple<int, int, int>;

bool is_uruu(int y) {
  if (y % 400 == 0) {
    return true;
  } else if (y % 100 == 0) {
    return false;
  } else if (y % 4 == 0) {
    return true;
  } else {
    return false;
  }
}

bool ok(tiii t) {
  if (get<0>(t) % get<1>(t) != 0)
    return false;
  int ym = get<0>(t) / get<1>(t);
  return ym % get<2>(t) == 0;
}

int mon[13][2] = {
    {},
    {31, 31},
    {28, 29},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
};

tuple<int, int, int> next(tiii t) {
  int y = get<0>(t);
  int m = get<1>(t);
  int d = get<2>(t);
  int lim = mon[m][is_uruu(y)];
  d++;
  if (d > lim) {
    d = 1;
    m++;
    if (m > 12) {
      m = 1;
      y++;
    }
  }
  return tiii(y, m, d);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int y, m, d;
  tiii t(stoi(s.substr(0, 4)), stoi(s.substr(5, 2)), stoi(s.substr(8, 2)));
  while (!ok(t)) {
    t = next(t);
  }
  printf("%04d/%02d/%02d\n", get<0>(t), get<1>(t), get<2>(t));

  return 0;
}
