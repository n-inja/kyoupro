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

using namespace std;
int n, k;
vector<long long> a, b;

typedef struct A {
  long long a, b;
} Node;

bool operator<(const Node &lhs, const Node &rhs) {
  return lhs.a < rhs.a;
}

int main() {
  cin >> n >> k;
  a.resize(n); b.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
  multiset<Node> s;
  for(int i = 0; i < n; i++) {
    Node nw;
    nw.a = a[i];
    nw.b = b[i];
    s.insert(nw);
  }
  long long ans = 0;
  for(int i = 0; i < k; i++) {
    Node no = *s.begin();
    ans += no.a;
    Node next;
    next.a = no.a + no.b;
    next.b = no.b;
    s.erase(s.begin());
    s.insert(next);
  }
  cout << ans << endl;
	return 0;
}
