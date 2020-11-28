#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
using namespace std;


template <typename T>
class Node {
public:
    Node(T obj, Node<T>* next)
        :next(next), obj(obj) {

    }
    Node(T obj)
        :Node(obj,nullptr){
    }
    T& get() {
        return obj;
    }
    Node<T> * getNext() {
        return next;
    }
    bool equals(Node<T> *other) {
        return equals(*other);
    }
    bool equals(Node<T>& other) {
        return equals(other.obj);
    }
    bool equals(T& other) {
        return other == obj;
    }
    void setNext(Node<T> * next) {
        this -> next = next;
    }
    void deleter() {
        if (next) {
            next -> deleter();
        }
        delete this;
        return;

    }
private:
    Node<T> *next;
    T obj;

};


#endif
