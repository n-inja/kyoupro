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
 
using namespace std;

struct Node {
  int id, back;
  int d;
};

bool operator<(const Node &lhs, const Node &rhs) {
  return lhs.d < rhs.d;
}

bool is(string s1, string s2) {
  int cnt = 0;
  for(int i = 0; i < s1.size(); i++) if(s1[i] != s2[i]) cnt++;
  return cnt == 1;
}

int main() {
  string st, ed;
  cin >> st >> ed;
  int n;
  cin >> n;
  vector<string> words(n + 2);
  words[0] = st;
  words[n + 1] = ed;
  for(int i = 0; i < n; i++) cin >> words[i + 1];
  n += 2;
  
  if(words[0] == words[n - 1]) {
    cout << 0 << endl;
    cout << words[0] << endl << words[0] << endl;
    return 0;
  }
  
  vector<int> back(n);
  for(int i = 0; i < n; i++) back[i] = -2;
  
  vector<vector<int>> path(n);
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(is(words[i], words[j])) path[i].push_back(j);
  
  multiset<Node> q;
  Node start{0, -1, 0};
  q.insert(start);
  while(q.size() > 0) {
    Node now = *q.begin();
    q.erase(q.begin());
    if(back[now.id] > -2) continue;
    back[now.id] = now.back;
    if(now.id == n - 1) {
      vector<int> ids;
      ids.push_back(n - 1);
      int parent = now.back;
      while(true) {
        ids.push_back(parent);
        parent = back[parent];
        if(parent < 0) break;
      }
      cout << ids.size() - 2 << endl;
      for(int i = 0; i < ids.size(); i++) cout << words[ids[ids.size() - 1 - i]] << endl;
      return 0;
    }
    for(int i = 0; i < path[now.id].size(); i++) {
      Node next{path[now.id][i], now.id, now.d + 1};
      q.insert(next);
    }
  }
  cout << -1 << endl;
  return 0;
}