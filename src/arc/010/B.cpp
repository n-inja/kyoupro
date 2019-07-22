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
  return get<0>(t) == 2012;
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
  int n;
  cin >> n;

  set<tiii> st;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    int y = 2012, m, d;
    int id = 0;
    for (int j = 0; j < t.size(); j++) if (t[j] == '/') id = j;
    m = stoi(t.substr(0, id));
    d = stoi(t.substr(id + 1, t.size()));
    tiii f(y, m, d);
    st.insert(f);
  }

  tiii t(2012, 1, 1);
  int w = 6;
  int stock = 0, now = 0, ans = 0;

  while (ok(t)) {
    if (st.find(t) != st.end()) {
      stock++;
    }
    if (w >= 5) {
      now++;
      ans = max(ans, now);
    } else if (stock > 0) {
      stock--;
      now++;
      ans = max(ans, now);
    } else {
      now = 0;
    }
    w++;
    w %= 7;
    t = next(t);
  }
  cout << ans << endl;
  return 0;
}
