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

// 14 * 15
// 4 * 5

int hx[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int hy[9] = {1, 0, -1, 1, 0, -1, 1, 0, -1};

int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int a;
    cin >> a;
    int w = 5, h = 4;
    if (a == 20) {
      cout << "2 2" << endl;
      int offsetX, offsetY;
      cin >> offsetX >> offsetY;
      bool ch[4][5] = {false};
      ch[0][0] = true;
      while (!ch[h - 1][0]) {
        cout << 1 + offsetX << " " << h - 2 + offsetY << endl;
        int x, y;
        cin >> x >> y;
        ch[y - offsetY][x - offsetX] = true;
      }
      while (!ch[3][4]) {
        cout << w - 2 + offsetX << " " << h - 2 + offsetY << endl;
        int x, y;
        cin >> x >> y;
        ch[y - offsetY][x - offsetX] = true;
      }
      while (!ch[0][4]) {
        cout << w - 2 + offsetX << " " << 1 + offsetY << endl;
        int x, y;
        cin >> x >> y;
        ch[y - offsetY][x - offsetX] = true;
      }
      while (true) {
        int maxScore = 0, ii, ij;
        for (int i = 1; i < h - 1; i++)
          for (int j = 1; j < w - 1; j++) {
            int score = 0;
            for (int l = 0; l < 9; l++)
              if (!ch[i + hy[l]][j + hx[l]])
                score++;
            if (maxScore < score) {
              maxScore = score;
              ii = i;
              ij = j;
            }
          }
        cout << ij + offsetX << " " << ii + offsetY << endl;
        int x, y;
        cin >> x >> y;
        if (x == y && x == 0) {
          break;
        }
        ch[y - offsetY][x - offsetX] = true;
      }
    } else {
      h = 14;
      w = 15;
      cout << "2 2" << endl;
      int offsetX, offsetY;
      cin >> offsetX >> offsetY;
      bool ch[14][15] = {false};
      ch[0][0] = true;
      while (!ch[h - 1][0]) {
        cout << 1 + offsetX << " " << h - 2 + offsetY << endl;
        int x, y;
        cin >> x >> y;
        ch[y - offsetY][x - offsetX] = true;
      }
      while (!ch[3][4]) {
        cout << w - 2 + offsetX << " " << h - 2 + offsetY << endl;
        int x, y;
        cin >> x >> y;
        ch[y - offsetY][x - offsetX] = true;
      }
      while (!ch[0][4]) {
        cout << w - 2 + offsetX << " " << 1 + offsetY << endl;
        int x, y;
        cin >> x >> y;
        ch[y - offsetY][x - offsetX] = true;
      }
      while (true) {
        int maxScore = 0, ii, ij;
        for (int i = 1; i < h - 1; i++)
          for (int j = 1; j < w - 1; j++) {
            int score = 0;
            for (int l = 0; l < 9; l++)
              if (!ch[i + hy[l]][j + hx[l]])
                score++;
            if (maxScore < score) {
              maxScore = score;
              ii = i;
              ij = j;
            }
          }
        cout << ij + offsetX << " " << ii + offsetY << endl;
        int x, y;
        cin >> x >> y;
        if (x == y && x == 0) {
          break;
        }
        ch[y - offsetY][x - offsetX] = true;
      }
    }
  }
  return 0;
}
