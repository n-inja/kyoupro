#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<int>> p(n);
  for (int i = 0; i < m; i++) {
    int t, f;
    cin >> t >> f;
    t--;
    f--;
    p[t].push_back(f);
    p[f].push_back(t);
  }
  int r[202020] = {0}, b[202020] = {0};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < p[i].size(); j++)
      if (s[p[i][j]] == 'A')
        r[i]++;
      else
        b[i]++;
  set<int> st;
  bool used[202020] = {0};
  for (int i = 0; i < n; i++)
    if ((r[i] == 0 || b[i] == 0) && !used[i]) {
      st.insert(i);
    }
  while (st.size() > 0) {
    int i = *st.begin();
    st.erase(st.begin());
    if (used[i])
      continue;
    used[i] = true;
    for (int j = 0; j < p[i].size(); j++) {
      if (s[i] == 'A')
        r[p[i][j]]--;
      else
        b[p[i][j]]--;
      if (r[p[i][j]] == 0 || b[p[i][j]] == 0)
        st.insert(p[i][j]);
    }
  }
  for (int i = 0; i < n; i++)
    if (r[i] > 0 && b[i] > 0) {
      cout << "Yes" << endl;
      return 0;
    }
  cout << "No" << endl;
  return 0;
}
