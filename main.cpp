#include "List.h"
#include <iostream>
using namespace std;

template <typename T> void showList(const List<T> &L) {
  for (auto i = L.first(); i != L.end(); i = i->succ)
    cout << i->data << ' ';
  cout << endl;
}

int main() {
  List<int> L;
  int n;
  cout << "Testing size: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    L.pushBack(rand() % 100 + 1);
  }

  auto M = L;

  cout << "\nList L: ";
  showList(L);

  L.selSort();
  cout << "\nL.selSorted()\n\n";

  cout << "List L: ";
  showList(L);

  cout << "\nM is copying from L.\n\nList M: ";
  showList(M);

  M.insSort();
  cout << "\nM.insSorted()\n\n";

  cout << "List M: ";
  showList(M);

  return 0;
}
