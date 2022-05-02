// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
  private:
  struct Item {
    T value;
    TItem * next;
    TItem * prev;
  };
  TPQueue :: Item * TRQueue :: creat(const T& value) {
    Item * item = new Item;
    item -> value = value;
    item -> next = nullptr;
    item -> ptev = nullptr;
    return item;
  }
  Item * head, * tail, * current;
 public:
  void push(const T& value) {
    if (!(head && tail)) {
      head = tail = creat(value);
    } else {
      Item * h = head;
      Item * v = creat(value);
      while (h && h -> value.prior >= value.prior) {
        h = h -> next;
        
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
