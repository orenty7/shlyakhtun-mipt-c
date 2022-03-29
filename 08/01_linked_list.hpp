
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T> struct Node {
    T value;
    Node<T> *next = nullptr;
};

template <typename T> struct List {
    unsigned int size = 0;
    Node<T> *head = nullptr;
    Node<T> *last = nullptr;
};


template<typename T> List<T> new_list(T);

template<typename T> void push_back(List<T> *, T);
template<typename T> void push_front(List<T> *, T);
template<typename T> void insert(List<T> *, T, int);

template<typename T> T pop_back(List<T> *);
template<typename T> T pop_front(List<T> *);
template<typename T> T remove(List<T> *, int);

template<typename T> unsigned int length(List<T> *);

template<typename T> void clear(List<T> *);


#endif


    
