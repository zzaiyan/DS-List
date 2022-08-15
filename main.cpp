#include "List.h"
#include <iostream>
using namespace std;

template <typename T> void showList(const List<T> &L) {
  for (auto i = L.first(); i != L.end(); i = i->succ)
    cout << i->date << ' ';
  cout << endl;
}

int main() {
  List<int> L;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    L.pushBack(rand() % 100 + 1);
  }

  cout << "List L: ";
  showList(L);

  auto M = L;

  L.selSort();
  cout << "List L is sorted\n";

  cout << "List L: ";
  showList(L);

  cout << "List M: ";
  showList(M);

  return 0;
}
