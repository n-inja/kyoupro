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

typedef struct {
  int val;
  int id;
} N;

bool operator<(const N &lhs, const N &rhs) {
  if(lhs.id == rhs.id) {
    return lhs.val < rhs.val;
  } else {
    return lhs.id > rhs.id;
  }
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(q), cor(m), corinv(m);
  for(int i = 0; i < q; i++) {
    cin >> a[i];
    a[i]--;
  }
  vector<N> ns(m);
  for(int i = 0; i < m; i++) ns[i].val = i;
  for(int i = 0; i < q; i++) ns[a[i]].id = i + 1;
  sort(ns.begin(), ns.end());
  for(int i = 0; i < m; i++) cor[ns[i].val] = i;
  for(int i = 0; i < m; i++) corinv[cor[i]] = i;
  vector<int> qid(n);
  vector<bool> b(q);
  reverse(a.begin(), a.end());
  vector<set<int>> p(m);
  for(int i = 0; i < n; i++) p[0].insert(i);
  for(int i = 0; i < q; i++) {
    if(p[corinv[a[i]]].size() == 0) {
      if(b[corinv[a[i]]]) continue;
      cout << "No" << endl;
      return 0;
    }
    auto it = p[corinv[a[i]]].begin();
    p[corinv[a[i]]].erase(it);
    int key = *it;
    qid[key]++;
    p[(corinv[a[i]] + 1) % m].insert(key);
    b[corinv[a[i]]] = true;
  }
  int an = qid[0];
  for(int i = 1; i < n; i++) if(an != qid[i]) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}
