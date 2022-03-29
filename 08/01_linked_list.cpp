#include <iostream>
#include "01_linked_list.hpp"

using namespace std;

template <typename T> void push_back(List<T> *list, T new_val) {
    if(list->size == 0) {
	*list = new_list(new_val);
	return;
    }
	
    Node<T> *new_node = new Node<T>{.value = new_val, .next = nullptr};
    list->last->next = new_node;
    list->last = new_node;
    list->size++;
}

template <typename T> void push_front(List<T> *list, T new_val) {
    if(list->size == 0) {
	*list = new_list(new_val);
	return;
    }

    Node<T> *new_node = new Node<T>{.value = new_val, .next = list->head};

    list->head = new_node;
    list->size++;
}

template <typename T> void insert(List<T> *list, T new_val, int index) {
    if (index == list->size - 1) {
        push_back<T>(list, new_val);
        return;
    }

    Node<T> *new_node = new Node<T>{.value = new_val};
    Node<T> *prev_node = list->head;
    for (int i = 0; i < index - 1; i++)
        prev_node = prev_node->next;

    Node<T> *next_node = prev_node->next;

    prev_node->next = new_node;
    new_node->next = next_node;
    list->size++;
}

template <typename T> T pop_back(List<T> *list) {
    Node<T> *before_last = list->head;

    for (int i = 0; i < list->size - 1; i++)
        before_last = before_last->next;

    Node<T> *last = list->last;

    before_last->next = nullptr;
    list->last = before_last;
    list->size--;

    T value = list->last->value;
    delete last;

    return value;
}

template <typename T> T pop_front(List<T> *list) {
    Node<T> *head = list->head;

    list->head = head->next;
    list->size--;

    T value = head->value;
    delete head;

    return value;
}

template <typename T> T remove(List<T> *list, int index) {
    if (index == 0)
        return pop_front(list);
    if (index == list->size - 1)
        return pop_back(list);

    Node<T> *prev_node = list->head;
    for (int i = 0; i < index - 1; i++)
        prev_node = prev_node->next;

    Node<T> *node = prev_node->next;
    Node<T> *next_node = node->next;

    prev_node->next = next_node;
    list->size--;

    T value = node->value;
    delete node;

    return value;
}

template <typename T> unsigned int length(List<T> *list) { return list->size; }

template <typename T> void clear(List<T> *list) {
    Node<T> *node = list->head;

    while (node->next != nullptr) {
        Node<T> *next = node->next;
        delete node;

        node = next;
    }
    delete node;
}

template <typename T> void print(List<T> *list) {
    Node<T> *node = list->head;
    for (int i = 0; i < list->size; i++) {
        cout << node->value << " ";
        node = node->next;
    }
    cout << "\n";
}

template <typename T> List<T> new_list(T val) {
    Node<T> *node = new Node<T>{.value = val, .next = nullptr};
    return {.size = 1, .head = node, .last = node};
}

int main() {
    List<int> l;

    print(&l);
    push_front<int>(&l, 10);
    print(&l);
   
    pop_back<int>(&l);
    print(&l);
    
    push_back<int>(&l, 11);
    push_back<int>(&l, 12);

    print(&l);
    cout << remove(&l, 1) << endl;
    print(&l);

    clear(&l);

    return 0;
}
