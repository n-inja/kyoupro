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

#define P 1000000007

using namespace std;

class LongMansionDiv2 {
public:
  LongMansionDiv2() {}
  long long minimalTime(int M, vector<int> t) {
    long long ans = 0;
    sort(t.begin(), t.end());
    for(int i = 0; i < t.size(); i++) {
      ans += t[i];
    }
    ans += t[0] * (M - 1);
    return ans;
  }
};


class LongLiveZhangzj {
public:
  LongLiveZhangzj() {}
  int donate(vector<string> speech, vector<string> words) {
    int ans = 0;
    sort(words.begin(), words.end());
    for(int i = 0; i < speech.size(); i++) {
      for(int j = 0; i < words.size(); j++) {
        if(speech[i] == words[j]) {
          ans++;
          break;
        }
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
