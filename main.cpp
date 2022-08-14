#include "List.h"
#include <iostream>
using namespace std;

int main() {
  List<int> L;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    L.pushBack(x);
    cout << "size = " << L.size() << endl;
  }

  for (auto i = L.first(); i != L.end(); i = i->succ)
    cout << i->date << ' ';

  cout << endl;

  // L[1] = 12345;

  // int m;
  // cin >> m;
  // while (m--) {
  //   int x;
  //   cin >> x;
  //   auto p = L.begin();
  //   while (x--)
  //     p = p->succ;
  //   auto temp = L.remove(p);
  //   cout << "É¾³ýÁË " << temp << endl;
  //   for (auto i = L.first(); i != L.end(); i = i->succ)
  //     cout << i->date << ' ';
  // }

  auto rmNum = L.uniquify();

  cout << "\nremove " << rmNum << " eles\n";

  for (auto i = L.first(); i != L.end(); i = i->succ)
    cout << i->date << ' ';

  cout << "\nsize = " << L.size() << endl;

  return 0;
}
