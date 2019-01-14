#include <bits/stdc++.h>

using namespace std;

int main() {
  int ue;
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (int i = 0; i < m; i++)
    cin >> v[i];
  vector<int> s(n);
  vector<int> sums(m + 1);
  sums[0] = n;
  int small = 0;
  for (int i = 0; i < m; i++) {
    sums[s[v[i] - 1]]--;
    if (sums[s[v[i] - 1]] == 0 && small == s[v[i] - 1]) {
      cout << 1;
      small++;
    } else {
      cout << 0;
    }
    s[v[i] - 1]++;
    sums[s[v[i] - 1]]++;
  }
  cout << endl;

  return 0;
}
