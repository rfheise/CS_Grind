#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
using namespace std;

template  <typename T>
class Node {
private:
    T obj; 
    Node *next;
    friend bool operator==(Node &left, T& obj) {
        return left.obj == obj;
    }
public:
    Node(T obj)
        :Node(obj, nullptr){

    }
    Node(T obj, Node *next) 
        :obj(obj),next(next) {

    }
    void deleter() {
        if (next) {
            next -> deleter();
        }
        delete this;
    }
    Node * getNext() {
        return next;
    }
    void setNext(Node * next) {
       this -> next = next;
    }

};


#endif