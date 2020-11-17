#ifndef _HASH_H_
#define _HASH_H_
#include "Node.h"


template <typename T>
class Hash {
public:
    static constexpr int default_size = 10000;
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
            tmp = nodes[hash];
            nodes[hash] = nodes[hash] -> getNext();
            delete tmp;
            size --;
            return;
        }
        Node<T> * temp = nodes[hash];
        while(temp -> getNext()) {
            if (temp -> getNext() -> equals(obj)) {
                tmp = temp -> getNext();
                temp -> setNext(tmp -> getNext());
                delete tmp;
                size --;
                return;
            }
            temp = temp -> getNext();
        }

    }
    int getSize() {
        return size;
    }
    ~Hash() {
        for (int i = 0; i < len; i++) {
            if (nodes[i] != nullptr) {
                nodes[i] -> deleter();
            }
        }
        delete nodes;
    }

private:
    Node<T> *tmp;
    Node<T> **nodes;
    int (*func)(T obj);
    int size;
    int len;
};

#endif
