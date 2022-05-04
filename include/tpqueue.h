// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
 private:
  struct Item {
    T value;
    Item * next;
    Item * prev;
  };
  TPQueue<T> :: Item * TPQueue<T> :: creat(const T& value) {
    Item * item = new Item;
    item -> value = value;
    item -> next = nullptr;
    item -> prev = nullptr;
    return item;
  }
  Item * head, * tail, * current;
 
 public:
  void push(const T& value) {
    Item * h = head;
    Item * v = creat(value);
    if (!(head && tail)) {
      head = tail = creat(value);
    } else {
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
    T value = head -> value;
    if (head -> next) {
      Item* zam = head -> next;
      head -> prev  = nullptr;
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
