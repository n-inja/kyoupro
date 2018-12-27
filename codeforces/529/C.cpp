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
  long long n, k;
  cin >> n >> k;
  map<long long, int> mp;
  long long m = n;
  long long l = 1;
  while (m > 0) {
    if (m % 2 == 1) {
      mp[-l]++;
    }
    m /= 2;
    l *= 2;
  }
  if (mp.size() > k || k > n) {
    cout << "NO" << endl;
    return 0;
  }
  long long now = mp.size();
  while (now < k) {
    auto it = mp.begin();
    if (it->first == -1) {
      cout << "NO" << endl;
      return 0;
    }
    if (it->second == 1) {
      long long j = it->first;
      mp[j / 2] += 2;
      now += 1;
      mp.erase(it);
    } else {
      it->second--;
      mp[it->first / 2] += 2;
      now += 1;
    }
  }
  cout << "YES" << endl;
  vector<long long> ans;
  for (auto &i : mp) {
    for (int j = 0; j < i.second; j++)
      ans.push_back(-i.first);
  }
  sort(ans.begin(), ans.end());
  cout << ans[0];
  for (int i = 1; i < ans.size(); i++)
    cout << " " << ans[i];
  cout << endl;

  return 0;
}
