#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

struct E {
  int i, j, t;
  bool erase;
};

struct P {
  ll s;
  ll sum;
  ll cnt;
  int t;
  bool erase;
};

void solve(int t) {
  ll ans = 0;
  int r, c;
  cin >> r >> c;
  vector<vector<P>> mp(r, vector<P>(c));
  vector<map<int, ll>> w(r);
  vector<map<int, ll>> h(c);
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      cin >> mp[i][j].s;
      w[i][j] = mp[i][j].s;
      h[j][i] = mp[i][j].s;
      mp[i][j].erase = false;
      mp[i][j].t = 0;
    }
  queue<E> q;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      mp[i][j].sum = 0;
      mp[i][j].cnt = 0;
      if (i > 0) {
        mp[i][j].sum += mp[i - 1][j].s;
        mp[i][j].cnt++;
      }
      if (j > 0) {
        mp[i][j].sum += mp[i][j - 1].s;
        mp[i][j].cnt++;
      }
      if (i + 1 < r) {
        mp[i][j].sum += mp[i + 1][j].s;
        mp[i][j].cnt++;
      }
      if (j + 1 < c) {
        mp[i][j].sum += mp[i][j + 1].s;
        mp[i][j].cnt++;
      }
      if (mp[i][j].s * mp[i][j].cnt < mp[i][j].sum) {
        q.push(E{i, j, 1, true});
      }
    }
  int turn = 0;
  while (q.size()) {
    auto now = q.front();
    q.pop();
    if (mp[now.i][now.j].erase) continue;
    turn = max(turn, now.t);
    if (now.erase) {
      ans += mp[now.i][now.j].s * turn;
      auto wit = w[now.i].lower_bound(now.j);
      auto hit = h[now.j].lower_bound(now.i);
      // left
      wit++;
      if (wit != w[now.i].end()) {
        q.push(E{now.i, wit->first, now.t, false});
      }
      wit--;
      // right
      if (wit != w[now.i].begin()) {
        wit--;
        q.push(E{now.i, wit->first, now.t, false});
      }
      // down
      hit++;
      if (hit != h[now.j].end()) {
        q.push(E{hit->first, now.j, now.t, false});
      }
      hit--;
      // up
      if (hit != h[now.j].begin()) {
        hit--;
        q.push(E{hit->first, now.j, now.t, false});
      }
      w[now.i].erase(now.j);
      h[now.j].erase(now.i);
      mp[now.i][now.j].erase = true;
    } else {
      if (mp[now.i][now.j].t >= now.t) continue;
      mp[now.i][now.j].t = now.t;
      mp[now.i][now.j].cnt = 0;
      mp[now.i][now.j].sum = 0;
      auto wit = w[now.i].lower_bound(now.j);
      auto hit = h[now.j].lower_bound(now.i);
      // left
      wit++;
      if (wit != w[now.i].end()) {
        mp[now.i][now.j].cnt++;
        mp[now.i][now.j].sum += wit->second;
      }
      wit--;
      // right
      if (wit != w[now.i].begin()) {
        mp[now.i][now.j].cnt++;
        wit--;
        mp[now.i][now.j].sum += wit->second;
      }
      // down
      hit++;
      if (hit != h[now.j].end()) {
        mp[now.i][now.j].cnt++;
        mp[now.i][now.j].sum += hit->second;
      }
      hit--;
      // up
      if (hit != h[now.j].begin()) {
        mp[now.i][now.j].cnt++;
        hit--;
        mp[now.i][now.j].sum += hit->second;
      }
      if (mp[now.i][now.j].s * mp[now.i][now.j].cnt < mp[now.i][now.j].sum) {
        q.push(E{now.i, now.j, now.t + 1, true});
      }
    }
  }
  turn += 1;
  for (auto &m : w) for (auto &pr : m) ans += pr.second * turn;
  cout << "Case #" << t << ": " << ans << endl;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) solve(i);
  return 0;
}
