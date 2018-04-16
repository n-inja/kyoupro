#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>

using namespace std;

class Node {
public:
  int value, size;
  Node *l = nullptr, *r = nullptr;
  Node(int val) {
    value = val;
    size = 1;
  }
  void append(int val) {
    size++;
    if (val <= value) {
      if (l == nullptr) {
        l = new Node(val);
      } else {
        l->append(val);
      }
    } else {
      if (r == nullptr) {
        r = new Node(val);
      } else {
        r->append(val);
      }
    }
  }
  bool same(Node *root) {
    if (this->size == root->size && root->size == 1)
      return true;
    if (this->size != root->size)
      return false;
    if ((this->l == nullptr xor root->l == nullptr) ||
        (this->r == nullptr xor root->r == nullptr))
      return false;
    if (this->l != nullptr) {
      if (!this->l->same(root->l))
        return false;
    }
    if (this->r != nullptr) {
      if (!this->r->same(root->r))
        return false;
    }
    return true;
  }
};

bool solve() {
  int n, k;
  if (scanf("%d %d", &n, &k) == EOF)
    return false;
  Node *arr[n];
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr[i] = new Node(a);
    for (int j = 1; j < k; j++) {
      cin >> a;
      arr[i]->append(a);
    }
  }
  bool ch[n];
  for (int i = 0; i < n; i++)
    ch[i] = true;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (ch[i]) {
      ans++;
      for (int j = i + 1; j < n; j++)
        if (arr[i]->same(arr[j])) {
          ch[j] = false;
        }
    }
  }
  cout << ans << endl;
  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}
