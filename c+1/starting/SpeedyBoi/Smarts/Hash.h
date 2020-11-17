#ifndef _HASH_H_
#define _HASH_H_
#include <memory>
#include "Node.h"
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
template <typename T>
class Hash {
public:
    static constexpr int default_size = 10000;
    Hash(int (*func)(T obj), int len = default_size)
        :func(func), size(0), len(len){
            nodes = make_unique<shared_ptr<Node<T>>[]>(len);
            for (int i = 0; i < len; i++) {
                nodes[i] = shared_ptr<Node<T>>(nullptr);
            }
    }

    void add(T obj){
        size_t hash = func(obj);
        hash %= len;
        nodes[hash] = shared_ptr<Node<T>>(new Node(obj, nodes[hash]));
        size++;
    }

    bool check(T obj) {
        size_t hash = func(obj);
        shared_ptr<Node<T>> temp = nodes[hash % len];
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
            size--;
            return;
        }
        shared_ptr<Node<T>> temp = nodes[hash];
        while(temp -> getNext()) {
            if (temp -> getNext() -> equals(obj)) {
                temp -> setNext(temp -> getNext() -> getNext());
                size --;
                return;
            }
            temp = temp -> getNext();
        }

    }
    int getSize() {
        return size;
    }

private:
    unique_ptr<shared_ptr<Node<T>>[]> nodes;
    int (*func)(T obj);
    int size;
    int len;
};

#endif
