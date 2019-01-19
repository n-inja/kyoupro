#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

struct MostFrequentLastDigit {
  vector<int> generate(int n, int d) {
    vi ans;
    if (d == 0) {
      for (int i = 0; i < n; i++)
        ans.push_back(5 + i * 10);
    } else {
      int a, b;
      if (d < 5) {
        a = d + 5;
        b = 5;
      } else {
        a = d - 1;
        b = 1;
      }
      if (d == 7) {
        a = d - 2;
        b = 2;
      }
      for (int i = 0; i < n / 2; i++)
        ans.push_back(a + i * 10);
      for (int i = n / 2; i < n; i++)
        ans.push_back(b + (i - n / 2) * 10);
    }
    return ans;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  MostFrequentLastDigit m;
  vi v = m.generate(5, 0);
  for (auto &i : v)
    cout << i << " ";
  cout << endl;
  v = m.generate(5, 1);
  for (auto &i : v)
    cout << i << " ";
  cout << endl;
  v = m.generate(5, 2);
  for (auto &i : v)
    cout << i << " ";
  cout << endl;
  v = m.generate(5, 3);
  for (auto &i : v)
    cout << i << " ";
  cout << endl;
  v = m.generate(5, 4);
  for (auto &i : v)
    cout << i << " ";
  cout << endl;
  v = m.generate(5, 5);
  for (auto &i : v)
    cout << i << " ";
  cout << endl;
  v = m.generate(5, 6);
  for (auto &i : v)
    cout << i << " ";
  cout << endl;
  v = m.generate(5, 7);
  for (auto &i : v)
    cout << i << " ";
  cout << endl;
  v = m.generate(5, 8);
  for (auto &i : v)
    cout << i << " ";
  cout << endl;
  v = m.generate(5, 9);
  for (auto &i : v)
    cout << i << " ";
  cout << endl;
  return 0;
}
