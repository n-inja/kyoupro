#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

int main() {
  int n, h, w;
  cin >> n >> h >> w;
  vector<int> x(n);
  for(int i = 0; i < n; i++) cin >> x[i];
  if(n % 2 == 1) {n++; x.push_back(0); }
  int ans = 0;
  for(int i = 0; i < n / 2; i++) {
    int lx = min(x[i * 2], w - x[i * 2 + 1]);
    int rx = min(w - x[i * 2], x[i * 2 + 1]);
    ans += (rx + lx) * h;
  }
  cout << ans << endl;
  return 0;
}
