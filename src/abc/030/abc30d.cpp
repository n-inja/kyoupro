#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<set>
#include<utility>

using namespace std;

long long power(long long e, long long x, long long m) {
  if(x == 0) return 1;
  if(x == 1) return e % m;
  if(x % 2 == 0) return power((e * e) % m, x / 2, m);
  else return (e * power(e, x - 1, m)) % m;
}

int main() {
  int n, a;
  cin >> n >> a;
  string k;
  cin >> k;
  int num = -1;
  if(k.size() < 7) num = stoi(k);
  vector<int> b(n);
  for(int i = 0; i < n; i++) cin >> b[i];
  for(int i = 0; i < n; i++) --b[i];
  a--;
  set<int> s;
  int now = a;
  vector<int> q;
  for(int i = 0; i <= n; i++) {
    if(num > 0 && i + 1 == num) {
      cout << b[now] + 1 << endl;
      return 0;
    }
    if(s.find(now) != s.end()) {
      long long ans = 0, st = 0, len = 0, loop = 0;
      for(int j = 0; j < q.size(); j++) if(q[j] == now) st = j;
      len = (int)q.size() - st;
      ans = st;
      for(int j = 0; j < k.size(); j++) {
        loop *= 10;
        loop += k[j] - '0';
        loop %= len;
      }
      loop = (loop - ans + len) % len;
      // cout << ans << " " << len << " " << loop << endl;
      // for(int j = 0; j < q.size(); j++) cout << q[j] << endl;
      cout << q[ans + loop] + 1 << endl;
      return 0;
    }
    s.insert(now);
    q.push_back(now);
    now = b[now];
  }
  return 0;
}
