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

  showList(L);

  auto M = L;

  L.selSort();
  cout << "L is sorted\n";

  showList(L);

  showList(M);

  return 0;
}
