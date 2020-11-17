#ifndef _NODE_H_
#define _NODE_H_
#include <memory>

#include <iostream>
using namespace std;

using std::unique_ptr;
using std::shared_ptr;
template <typename T>
class Node {
public:
    Node(T obj, Node<T>* next)
        :obj(obj),next(next) {

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
