#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class SA {
  int n;
  string s;
public:
  vector<int> rank, sa;

  SA(string s) : s(s) {
    n = s.size();
    rank.resize(n + 1);
    sa.resize(n + 1);
    for (int i = 0; i < n; i++) rank[i] = s[i];
    s[n] = -1;
    for (int i = 0; i <= n; i++) sa[i] = i;
    vector<int> tmp(n + 1);
    for (int k = 1; k <= n; k <<= 1) {
      function<bool(int, int)> comp = [&](int i, int j) {
        if (rank[i] != rank[j]) {
          return rank[i] < rank[j];
        } else {
          int lvalue = i + k <= n ? rank[i + k] : -1;
          int rvalue = j + k <= n ? rank[j + k] : -1;
          return lvalue < rvalue;
        }
      };
      sort(sa.begin(), sa.end(), comp);
      tmp[sa[0]] = 0;
      for (int i = 0; i < n; i++) {
        tmp[sa[i + 1]] = tmp[sa[i]] + (comp(sa[i], sa[i + 1]) ? 1 : 0);
      }
      rank = tmp;
    }
  }

  bool contains(string t) {
    if (t.size() == 0) return true;
    int l = 0, r = n;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (s.compare(sa[m], t.size(), t) < 0) {
        l = m;
      } else {
        r = m;
      }
    }
    return s.compare(sa[r], t.size(), t) == 0;
  }
};

int main() {
  SA sa("abracadabra");
  cerr << sa.contains("abracadabra") << endl;
  return 0;
}