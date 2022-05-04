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
        if (!h -> prev) {
          head -> prev = v;
          v -> next = head;
          head = v;
        } else if (!h && head) {
          tail -> next = v;
          v -> prev = tail;
          tail = v;
        } else {
          h -> prev -> next = v;
          v -> prev = h -> prev;
          v -> next = h;
          h -> prev = v;
        }
      }
    }
  }
  T pop() {
    if (head -> next) {
      ITEM* zam = head -> next;
      h -> prev  = nullptr;
      T value = head -> value;
      delete head;
      head = zam;
    } else {
      tail = nullptr;
    }
    return value;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
