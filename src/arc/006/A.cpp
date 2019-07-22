#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
int b;
int e[6];
int f[6];

bool ok1() {
  set<int> s;
  for (int i = 0; i < 6; i++) s.insert(e[i]);
  for (int j = 0; j < 6; j++) if (s.find(f[j]) == s.end()) return false;
  return true;
}

bool ok2() {
  set<int> s;
  for (int i = 0; i < 6; i++) s.insert(e[i]);
  s.insert(b);
  for (int j = 0; j < 6; j++) if (s.find(f[j]) == s.end()) return false;
  return true;
}

bool ok(int c) {
  set<int> s;
  for (int i = 0; i < 6; i++) s.insert(e[i]);
  for (int j = 0; j < 6; j++) if (s.find(f[j]) == s.end()) c--;
  return c >= 0;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  for (int i = 0; i < 6; i++) cin >> e[i];
  cin >> b;
  for (int i = 0; i < 6; i++) cin >> f[i];
  sort(e, e + 6);
  sort(f, f + 6);
  if (ok1()) cout << 1 << endl;
  else if (ok2()) cout << 2 << endl;
  else if (ok(1)) cout << 3 << endl;
  else if (ok(2)) cout << 4 << endl;
  else if (ok(3)) cout << 5 << endl;
  else cout << 0 << endl;
  return 0;
}
