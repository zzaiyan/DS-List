#include "List.h"
#include <iostream>
using namespace std;

int getRank(List<int> &L, ListNode<int> *p) {
  int n = 0;
  while (p != L.begin()) {
    p = p->pred;
    n++;
  }
  return n;
}

ListNode<int> *getNode(List<int> &L, int n) {
  auto p = L.begin();
  while (n--)
    p = p->succ;
  return p;
}

int main() {
  List<int> L;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    L.pushBack(rand() % 100 + 1);
  }
  // while (n--) {
  //   // string in;
  //   // cin >> in;
  //   int x, y;
  //   cin >> x >> y;
  //   L.insertAfter(L.begin()->pred, x);
  //   L.insertBefore(L.end(), y);
  //   for (auto i = L.first(); i != L.end(); i = i->succ)
  //     cout << i->date << ' ';
  //   cout << endl;
  // }

  for (auto i = L.first(); i != L.end(); i = i->succ)
    cout << i->date << ' ';

  cout << endl;

  for (int i = 1; i <= n; i++) {
    auto e = L.selMax(L.begin(), i);
    cout << e->date << " ";
  }
  cout << endl;

  for (auto i = L.first(); i != L.end(); i = i->succ)
    cout << i->date << ' ';

  L.selSort(L.begin(), L.size());

  // cout << "\nremove " << rmNum << " eles\n";
  cout << endl;

  for (auto i = L.first(); i != L.end(); i = i->succ)
    cout << i->date << ' ';

  cout << "\nsize = " << L.size() << endl;

  return 0;
}
