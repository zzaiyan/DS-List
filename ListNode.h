#pragma once
#include <iostream>

template <typename T> struct ListNode {
  T date;
  ListNode<T> *pred, *succ;

  ListNode() {}
  //~ListNode() { std::cout << "ListNode Distruction Called\n"; }
  ListNode(const T &e, ListNode<T> *p = nullptr, ListNode<T> *s = nullptr)
      : date(e), pred(p), succ(s) {}
  ListNode<T> *insertAsPred(const T &e);
  ListNode<T> *insertAsSucc(const T &e);
  static const T &remove(ListNode<T> *p);
};

template <typename T> ListNode<T> *ListNode<T>::insertAsPred(const T &e) {
  ListNode<T> *x = new ListNode<T>(e, pred, this);
  pred->succ = x, pred = x;
  return x;
}

template <typename T> ListNode<T> *ListNode<T>::insertAsSucc(const T &e) {
  ListNode<T> *x = new ListNode<T>(e, this, succ);
  succ->pred = x, succ = x;
  return x;
}

template <typename T> const T &ListNode<T>::remove(ListNode<T> *p) {
  p->pred->succ = p->succ;
  p->succ->pred = p->pred;
  T temp = p->date;
  delete p;
  return temp;
}