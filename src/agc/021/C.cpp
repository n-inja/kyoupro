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

bool f(int n, int m, int a, int b, vector<string> &mp) {
  if (n == 1 || m == 1)
    return false;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      mp[i][j] = '.';
  if (b) {
    b--;
    mp[n - 3][m - 3] = '^';
    mp[n - 2][m - 3] = 'v';
  }
  if (b) {
    b--;
    mp[n - 2][m - 1] = '^';
    mp[n - 1][m - 1] = 'v';
  }
  if (a) {
    a--;
    mp[n - 3][m - 2] = '<';
    mp[n - 3][m - 1] = '>';
  }
  if (a) {
    a--;
    mp[n - 1][m - 3] = '<';
    mp[n - 1][m - 2] = '>';
  }
  int hok = n / 2 - 1;
  int wok = m / 2 - 1;
  for (int i = 0; i < hok; i++) {
    if (b > 0) {
      b--;
      mp[n - 4 - i * 2 - 1][m - 1] = '^';
      mp[n - 4 - i * 2][m - 1] = 'v';
    }
  }
  for (int i = 0; i < wok; i++) {
    if (a > 0) {
      a--;
      mp[n - 1][m - 4 - i * 2 - 1] = '<';
      mp[n - 1][m - 4 - i * 2] = '>';
    }
  }
  for (int i = 0; i < n / 2; i++)
    for (int j = 0; j < m / 2; j++) {
      if (i == n / 2 - 1 && j == m / 2 - 1)
        continue;
      if (a > 0) {
        a--;
        mp[i * 2][j * 2] = '<';
        mp[i * 2][j * 2 + 1] = '>';
        if (a > 0) {
          a--;
          mp[i * 2 + 1][j * 2] = '<';
          mp[i * 2 + 1][j * 2 + 1] = '>';
        }
      } else if (b > 0) {
        b--;
        mp[i * 2][j * 2] = '^';
        mp[i * 2 + 1][j * 2] = 'v';
        if (b > 0) {
          b--;
          mp[i * 2][j * 2 + 1] = '^';
          mp[i * 2 + 1][j * 2 + 1] = 'v';
        }
      }
    }
  if (a + b > 0)
    return false;
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    cout << mp[i] << endl;
  }
  return true;
}

int main() {
  int a, b, n, m, oa, ob;
  cin >> n >> m >> a >> b;
  oa = a;
  ob = b;
  vector<string> mp(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      mp[i].push_back('.');
  int hok = (m % 2 == 1) ? n / 2 : 0;
  int wok = (n % 2 == 1) ? m / 2 : 0;
  for (int i = 0; i < hok; i++) {
    if (b > 0) {
      b--;
      mp[n - 1 - i * 2 - 1 - n % 2][m - 1] = '^';
      mp[n - 1 - i * 2 - n % 2][m - 1] = 'v';
    }
  }
  for (int i = 0; i < wok; i++) {
    if (a > 0) {
      a--;
      mp[n - 1][m - 1 - i * 2 - 1 - m % 2] = '<';
      mp[n - 1][m - 1 - i * 2 - m % 2] = '>';
    }
  }
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < m / 2; j++) {

      if (a > 0) {
        a--;
        mp[i * 2][j * 2] = '<';
        mp[i * 2][j * 2 + 1] = '>';
        if (a > 0) {
          a--;
          mp[i * 2 + 1][j * 2] = '<';
          mp[i * 2 + 1][j * 2 + 1] = '>';
        }
      } else if (b > 0) {
        b--;
        mp[i * 2][j * 2] = '^';
        mp[i * 2 + 1][j * 2] = 'v';
        if (b > 0) {
          b--;
          mp[i * 2][j * 2 + 1] = '^';
          mp[i * 2 + 1][j * 2 + 1] = 'v';
        }
      }
    }
  }

  if (a + b > 0) {
    if (n % 2 == 1 && m % 2 == 1 && f(n, m, oa, ob, mp))
      return 0;
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << mp[i] << endl;
    }
  }
  return 0;
}
