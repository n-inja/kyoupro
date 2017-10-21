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

int h, w, a, b;

bool isT(vector<string> mp) {
  bool ret = true;
  for(int i = 0; i < h / 2; i++) for(int j = 0; j < w; j++) if(mp[i][j] != mp[h - i - 1][j]) ret = false;
  return ret;
}

bool isY(vector<string> mp) {
  bool ret = true;
  for(int i = 0; i < h; i++) for(int j = 0; j < w / 2; j++) if(mp[i][j] != mp[i][w - j - 1]) ret = false;
  return ret;
}

int count(vector<string> mp) {
  int ret = 0;
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(mp[i][j] == 'S') ret++;
  return ret;
}

long long solveT(vector<string> mp) {
  long long ans = 0;
  int cnt = 0;
  for(int i = 0; i < h; i++) for(int j = 0; j < w / 2; j++) if(mp[i][j] != mp[i][w - j - 1]) cnt++;
  for(int i = 0; i < h; i++) for(int j = 0; j < w / 2; j++) if(mp[i][j] != mp[i][w - j - 1]) mp[i][j] = mp[i][w - j - 1] = '.';
  ans = a * cnt / 2 + b;
  if(count(mp) == 0) {
    return ans;
  }
  ans += count(mp) / 2 * max(a, b) + count(mp) / 4 * min(a, b);
  return ans;
}

long long solveY(vector<string> mp) {
  int cnt = 0, ans = 0;
  for(int i = 0; i < h / 2; i++) for(int j = 0; j < w; j++) if(mp[i][j] != mp[h - i - 1][j]) cnt++;
  for(int i = 0; i < h; i++) for(int j = 0; j < w / 2; j++) if(mp[i][j] != mp[h - i - 1][j]) mp[i][j] = mp[h - i - 1][j] = '.';
  ans = b * cnt / 2 + a;
  if(count(mp) == 0) {
    return ans;
  }
  ans += count(mp) / 2 * max(a, b) + count(mp) / 4 * min(a, b);
  return ans;
}

int main() {
  cin >> h >> w >> a >> b;
  vector<string> mp(h);
  for(int i = 0; i < h; i++) cin >> mp[i];

  long long ans = 0;
  if(isT(mp) && isY(mp)) {
    if(count(mp) == 0) {
      cout << 0 << endl;
      return 0;
    }
    ans = count(mp) / 2 * max(a, b) + count(mp) / 4 * min(a, b);
    cout << ans << endl;
    return 0;
  }
  if(isT(mp)) {
    cout << solveT(mp) << endl;
    return 0;
  }
  if(isY(mp)) {
    cout << solveY(mp) << endl;
    return 0;
  }

  vector<string> mp2(h);
  for(int i = 0; i < h; i++) mp2[i] = mp[i];

  for(int i = 0; i < h; i++) for(int j = 0; j < w / 2; j++) if(mp[i][j] != mp[i][w - j - 1]) mp[i][j] = mp[i][w - j - 1] = '.';
  for(int i = 0; i < h / 2; i++) for(int j = 0; j < w; j++) if(mp2[i][j] != mp2[h - i - 1][j]) mp2[i][j] = mp2[h - i - 1][j] = '.';
  long long ans1 = solveT(mp2) + a, ans2 = solveY(mp) + b;
  if(isY(mp)) {
    ans1 = a + b;
    ans1 += count(mp) / 2 * max(a, b) + count(mp) / 4 * min(a, b);
  }
  if(isT(mp2)) {
    ans2 = a + b;
    ans2 += count(mp2) / 2 * max(a, b) + count(mp2) / 4 * min(a, b);
  }
  if(count(mp2) == 0) ans1 = a + b;
  if(count(mp) == 0) ans2 = a + b;

  cout << max(ans1, ans2) << endl;
  return 0;
}
