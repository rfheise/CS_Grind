#ifndef _HASH_H_
#define _HASH_H_
#include "Node.h"
template <typename T>
class Hash {
public:
    static constexpr int default_size = 1000000;
    Hash(int (*func)(T obj), int len = default_size)
        :func(func), size(0), len(len){
            nodes = new Node<T>*[len];
            for (int i = 0; i < len; i++) {
                nodes[i] = nullptr;
            }
    }

    void add(T obj){
        size_t hash = func(obj);
        hash %= len;
        nodes[hash] = new Node(obj, nodes[hash]);
        size++;
    }

    bool check(T obj) {
        size_t hash = func(obj);
        Node<T> * temp = nodes[hash % len];
        while(temp){
            if (temp -> equals(obj)) {
                return true;
            }
            temp = temp -> getNext();
        }
        return false;
    }
    void remove(T obj) {
        size_t hash = func(obj);
        hash %= len;
        if (!nodes[hash]) {
            return;
        }
        if (nodes[hash] -> equals(obj)) {
            nodes[hash] = nodes[hash] -> getNext();
            size --;
            return;
        }
        Node<T> * temp = nodes[hash];
        while(temp -> getNext()) {
            if (temp -> getNext() -> equals(obj)) {
                temp -> setNext(temp -> getNext() -> getNext());
                size --;
                return;
            }
        }

    }
    int getSize() {
        return size;
    }
    ~Hash() {
        delete[] nodes;
    }

private:
    Node<T> **nodes;
    int (*func)(T obj);
    int size;
    int len;
};

#endif
