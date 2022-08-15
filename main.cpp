#include "List.h"
#include <iostream>
using namespace std;

int main() {
  List<int> L;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    L.pushBack(rand() % 100 + 1);
  }

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
