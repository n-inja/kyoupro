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

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if(s.size() > 1000) return 0;
  vector<vector<int>> score(n + 1);
  for(int i = 0; i < n + 1; i++) {
    score[i].resize(3000);
    for(int j = 0; j < 3000; j++) {
      score[i][j] = -114514;
    }
  }
  const int piv = 1500;
  score[0][piv] = 0;

  for(int i = 0; i < n; i++) {
    if(s[i] == 'M') {
      for(int j = 0; j < 3000; j++) {
        if(j > 0 && j < 3000) {
          score[i + 1][j] = max(score[i][j - 1], score[i][j + 1]);
        } else if(j == 0) score[i + 1][j] = score[i][j + 1];
        else if(j == 2999) score[i + 1][j] = score[i][j - 1];
      }
    } else {
      for(int j = 0; j < 3000; j++) {
        if(s[i] == '+') {
          score[i + 1][j] = score[i][j] + j - piv;
        } else {
          score[i + 1][j] = score[i][j] - (j - piv);
        }
      }
    }
  }
  cout << score[n][piv] << endl;
  return 0;
}
