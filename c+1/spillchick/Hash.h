#ifndef _HASH_H_
#define _HASH_H_
#include "Node.h"
#include <cstdlib>
#include <iostream>

using namespace std;
const int standard = 1000000;

template <typename T>
class Hash {
private:
    int size;
    Node<T> **nodes;
    int (*hash)(T obj);
    int arrsize;
public:
    Hash(int (*hash)(T obj), int arrsize = standard)
        :hash(hash),arrsize(arrsize),size(0){
            nodes = new Node<T> *[arrsize];
            for (int i = 0; i < arrsize; i++) {
                nodes[i] = nullptr;
            }

    }
    
    //add object to hash table
    bool add(T &&obj) {
        return add(obj);
    }
    bool add(T &obj) {
        size_t code = hash(obj);
        code %= arrsize;
        Node<T> *n = new Node<T>(obj, nodes[code]);
        nodes[code] = n;
        size ++;
        return true;
    }
    //checks to see if object is in hash table
    bool check(T &&obj) {
        return check(obj);
    }
    bool check(T& obj) {
        size_t code = hash(obj);
        code %= arrsize;
        Node<T> *temp = nodes[code];
        while (temp) {
            if (*temp == obj) {
                return true;
            }
            temp = temp -> getNext();
        }
        return false;
    }
    //removes all instances of the object from the hash table
    bool remove(T &&obj) {
        return remove(obj);
    }
    bool remove(T &obj) {
        size_t code = hash(obj);
        code %= arrsize;
        Node<T> *temp = nodes[code];
        Node<T> *tmp;
        while (temp && (tmp = temp -> getNext())) {
            if (*tmp == obj) {
                temp -> setNext(tmp -> getNext());
                delete tmp;
            } else {
                temp = temp -> getNext();
            }
            
        }
        if (*nodes[code] == obj) {
            nodes[code] = nodes[code] -> getNext();
        }
        return true;
    }
    //get size of hash table
    int getSize() {
        return size;
    }
    ~Hash() {
        for (int i = 0; i < arrsize; i++) {
            if (nodes[i]) {
                nodes[i] -> deleter();
            }
            
        }
        delete[] nodes;
    }

};

#endif