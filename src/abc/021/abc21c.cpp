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

#define P 1000000007

using namespace std;

class Node {
public:
  int now, d;
  Node(int _, int __) {
    now = _;
    d = __;
  }
  bool operator<(const Node &rhs) const {
    return this->d < rhs.d;
  }
  bool operator>(const Node &rhs) const {
    return this->d > rhs.d;
  }
};

int main() {
  int n, a, b, m;
  cin >> n >> a >> b >> m;
  a--; b--;
  vector<vector<int>> p(n);
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    p[x].push_back(y);
    p[y].push_back(x);
  }
  vector<long long> dp(n);
  dp[a] = 1;
  multiset<Node> q;
  vector<int> check(n);
  q.insert(Node(a, 1));
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(check[now.now] > now.d) continue;
    check[now.now] = now.d;
    if(now.now == b) {
      cout << dp[now.now] << endl;
      return 0;
    }
    for(int i = 0; i < p[now.now].size(); i++) {
      if(check[p[now.now][i]] == now.d + 1) {
        dp[p[now.now][i]] = (dp[p[now.now][i]] + dp[now.now]) % P;
        continue;
      } else if(check[p[now.now][i]] == 0) {
        check[p[now.now][i]] = now.d + 1;
        dp[p[now.now][i]] = (dp[p[now.now][i]] + dp[now.now]) % P;
        q.insert(Node(p[now.now][i], now.d + 1));
      }
    }

  }

  return 0;
}
