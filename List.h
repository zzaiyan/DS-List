#pragma once
#include "ListNode.h"

template <typename T> class List {
  int _size;
  ListNode<T> *header;
  ListNode<T> *trailer;

protected:
  void _init();

public:
  List() { _init(); }
  // List(NodeList<T>*p,int n);
  ~List();
  //  ������ĩ�ڵ�
  ListNode<T> *first() const { return header->succ; }
  ListNode<T> *last() const { return trailer->pred; }
  ListNode<T> *begin() const { return header->succ; }
  ListNode<T> *end() const { return trailer; }
  //
  int size() { return _size; }
  // ����p��n����ǰ����ֵΪe�Ľڵ�
  ListNode<T> *find(const T &e, int n, ListNode<T> *p);
  // ����p��n��������ֵΪe�Ľڵ�
  ListNode<T> *find(const T &e, ListNode<T> *p, int n);
  // ǰ��
  ListNode<T> *insertBefore(ListNode<T> *p, const T &e);
  // ���
  ListNode<T> *insertAfter(ListNode<T> *p, const T &e);
  // ��β
  ListNode<T> *pushFront(const T &e);
  ListNode<T> *pushBack(const T &e);
  // ѭ�ȷ���
  T &operator[](int r);
  // ���ƽڵ�
  void copyNodes(ListNode<T> *p, int n);
  // ɾ���ڵ�
  const T &remove(ListNode<T> *p);
  // �������
  int clear();
  // Ψһ��
  int deduplicate();
  // Ψһ�� - ����
  int uniquify();
  // ���� (ʼ��p��n������Ԫ��)
  void selSort(ListNode<T> *p, int n);
  ListNode<T> *selMax(ListNode<T> *p, int n);
};

template <typename T> List<T>::~List() {
  clear();
  delete header;
  delete trailer;
}

template <typename T> void List<T>::_init() {
  // if (header)
  //   delete header;
  // if (trailer)
  //   delete trailer;
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
  _init();
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
      p = q; // ������ �������һ�׶�
    else
      remove(q); // ����ͬ ���Ƴ�q�ڵ�
  }
  return oldSize - _size;
}

template <typename T> void List<T>::selSort(ListNode<T> *p, int n) {
  ListNode<T> *head = p->pred, *tail = p;
  for (int i = 0; i < n; i++)
    tail = tail->succ;
  for (; n > 1; n--) {
    auto e = std::move(remove(selMax(head->succ, n)));
    // std::cout << "\nremove " << e;
    insertBefore(tail, e);
    tail = tail->pred;
  }
}

template <typename T> ListNode<T> *List<T>::selMax(ListNode<T> *p, int n) {
  ListNode<T> *m = p;
  while (--n) {
    p = p->succ;
    // �����ڵ��� ����� m
    if (!(p->date < m->date))
      m = p;
  }
  return m;
}
