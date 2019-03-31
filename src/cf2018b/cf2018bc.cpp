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
  int n;
  cin >> n;
  int c = 0;
  int a = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j % 5 == c) {
        cout << 'X';
        a++;
      } else {
        if (i == 0) {
          if (j % 5 == (c + 3) % 5) {
            cout << 'X';
            a++;
          } else
            cout << '.';
        } else if (i == n - 1) {
          if (j % 5 == (c + 3) % 5 || j == n - 1) {
            cout << 'X';
            a++;
          } else {
            cout << '.';
          }
        } else if (j == 0) {
          if (j % 5 == (c + 3) % 5) {
            cout << 'X';
            a++;
          } else
            cout << '.';
        } else if (j == n - 1) {
          if (j % 5 == (c + 2) % 5) {
            cout << 'X';
            a++;
          } else
            cout << '.';
        } else {
          cout << '.';
        }
      }
    }
    cout << endl;
    c += 2;
    c %= 5;
  }
  return 0;
}
