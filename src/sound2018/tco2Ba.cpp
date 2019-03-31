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

class SubarrayAverages {
public:
  SubarrayAverages() {}
  vector<double> findBest(vector<int> a) {
    int n = a.size();
    vector<double> ret(n);
    for (int i = 0; i < n; i++)
      ret[i] = a[i];
    for (int i = 1; i < n; i++) {
      if (ret[i] < ret[i - 1]) {
        double sum = ret[i];
        bool b = false;
        for (int k = 1; i - k >= 0; k++) {
          sum += ret[i - k];
          if (sum / (k + 1) > ret[i - k]) {
            sum -= ret[i - k];
            for (int j = 0; j < k; j++)
              ret[i - k + 1 + j] = sum / k;
            b = true;
            break;
          }
        }
        if (!b) {
          for (int j = 0; j <= i; j++)
            ret[j] = sum / (i + 1);
        }
      }
    }
    return ret;
  }
};

int main() {
  SubarrayAverages s;
  vector<int> a;
  a.push_back(1);
  a.push_back(10);
  a.push_back(1);
  a.push_back(1);
  a.push_back(1);
  a.push_back(1);
  a.push_back(10);
  vector<double> v = s.findBest(a);
  for (int i = 0; i < v.size(); i++) {
    printf("%.9lf ", v[i]);
  }
  cout << endl;
  return 0;
}
