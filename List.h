#pragma once
#include "ListNode.h"

template <typename T> class List {
  int _size;
  ListNode<T> *header, *trailer;

protected:
  void _init();

public:
  List() { _init(); }
  List(ListNode<T> *p, int n);
  List(const List<T> &L);
  ~List();
  // 重载赋值
  List<T> &operator=(const List<T> &L);
  // 返回首末节点
  ListNode<T> *first() const { return header->succ; }
  ListNode<T> *last() const { return trailer->pred; }
  ListNode<T> *begin() const { return header->succ; }
  ListNode<T> *end() const { return trailer; }
  // 返回元素个数
  int size() { return _size; }
  // 返回p的n个真前驱中值为e的节点
  ListNode<T> *find(const T &e, int n, ListNode<T> *p);
  // 返回p的n个真后继中值为e的节点
  ListNode<T> *find(const T &e, ListNode<T> *p, int n);
  // 前插
  ListNode<T> *insertBefore(ListNode<T> *p, const T &e);
  // 后插
  ListNode<T> *insertAfter(ListNode<T> *p, const T &e);
  // 首尾
  ListNode<T> *pushFront(const T &e);
  ListNode<T> *pushBack(const T &e);
  // 循秩访问
  T &operator[](int r);
  // 复制节点(用于拷贝构造or赋值)
  void copyNodes(ListNode<T> *p, int n);
  // 删除节点 返回其值
  const T &remove(ListNode<T> *p);
  // 清空内容
  int clear();
  // 唯一化
  int deduplicate();
  // 唯一化 - 有序
  int uniquify();
  // 排序 (始于p的n个连续元素)
  void selSort(ListNode<T> *p, int n);
  void selSort();
  // 搜索最大值
  ListNode<T> *selMax(ListNode<T> *p, int n);
  ListNode<T> *selMax();
};

template <typename T> List<T>::List(ListNode<T> *p, int n) {
  _init();
  copyNodes(p, n);
}

template <typename T> List<T>::List(const List<T> &L) {
  _init();
  copyNodes(L.header->succ, L._size);
}

template <typename T> List<T>::~List() {
  clear();
  delete header;
  delete trailer;
}

template <typename T> List<T> &List<T>::operator=(const List<T> &L) {
  clear();
  copyNodes(L.header->succ, L._size);
  return *this;
}

template <typename T> void List<T>::_init() {
  header = new ListNode<T>();
  trailer = new ListNode<T>();
  header->succ = trailer;
  trailer->pred = header;
  _size = 0;
}

template <typename T> T &List<T>::operator[](int r) {
  ListNode<T> *p = first();
  while (r-- > 0)
    p = p->succ;
  return p->date;
}

template <typename T> void List<T>::copyNodes(ListNode<T> *p, int n) {
  while (n--) {
    pushBack(p->date);
    p = p->succ;
  }
}

template <typename T>
ListNode<T> *List<T>::find(const T &e, int n, ListNode<T> *p) {
  while (n-- > 0) {
    p = p->pred;
    if (e == p->date)
      return p;
  }
  return nullptr;
}

template <typename T>
ListNode<T> *List<T>::find(const T &e, ListNode<T> *p, int n) {
  while (n-- > 0) {
    p = p->succ;
    if (e == p->date)
      return p;
  }
  return nullptr;
}

template <typename T>
ListNode<T> *List<T>::insertBefore(ListNode<T> *p, const T &e) {
  _size++;
  return p->insertAsPred(e);
}

template <typename T>
ListNode<T> *List<T>::insertAfter(ListNode<T> *p, const T &e) {
  _size++;
  return p->insertAsSucc(e);
}

template <typename T> ListNode<T> *List<T>::pushFront(const T &e) {
  return insertAfter(header, e);
}

template <typename T> ListNode<T> *List<T>::pushBack(const T &e) {
  return insertBefore(trailer, e);
}

template <typename T> const T &List<T>::remove(ListNode<T> *p) {
  _size--;
  return ListNode<T>::remove(p);
}

template <typename T> int List<T>::clear() {
  int oldSize = _size;
  while (_size > 0)
    remove(header->succ);
  return oldSize;
}

template <typename T> int List<T>::deduplicate() {
  if (_size < 2)
    return 0;
  int oldSize = _size, r = 1;
  auto p = first();
  while (p->succ != trailer) {
    p = p->succ;
    auto q = find(p->date, r, p);
    q ? remove(q) : r++;
  }
  return oldSize - _size;
}

template <typename T> int List<T>::uniquify() {
  if (_size < 2)
    return 0;
  int oldSize = _size;
  ListNode<T> *p = first(), *q;
  while (p->succ != trailer) {
    q = p->succ;
    if (q->date != p->date)
      p = q; // 若相异 则进入下一阶段
    else
      remove(q); // 若相同 则移除q节点
  }
  return oldSize - _size;
}

template <typename T> void List<T>::selSort(ListNode<T> *p, int n) {
  ListNode<T> *head = p->pred, *tail = p;
  for (int i = 0; i < n; i++)
    tail = tail->succ;
  for (; n > 1; n--) {
    insertBefore(tail, remove(selMax(head->succ, n)));
    tail = tail->pred;
  }
}

template <typename T> ListNode<T> *List<T>::selMax(ListNode<T> *p, int n) {
  ListNode<T> *m = p;
  while (--n) {
    p = p->succ;
    // 若大于等于 则更新 m
    if (!(p->date < m->date))
      m = p;
  }
  return m;
}

template <typename T> void List<T>::selSort() { selSort(header->succ, _size); }

template <typename T> ListNode<T> *List<T>::selMax() {
  return selMax(header->succ, _size);
}
