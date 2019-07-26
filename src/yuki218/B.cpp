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
  ll n = s.size();
  ll div = n * (n + 1) / 2;
  ll sum = 0;
  set<char> st;
  for (char &c : s) st.insert(c);
  for (auto &c : st) {
    ll sub = n * (n + 1) / 2;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == c) {
        sub -= (cnt * (cnt + 1) / 2);
        cnt = 0;
      } else {
        cnt++;
      }
    }
    sub -= (cnt * (cnt + 1) / 2);
    sum += sub;
  }

  printf("%.12lf\n", (double) sum / div);
  return 0;
}
