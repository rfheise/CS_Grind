#ifndef _NODE_H_
#define _NODE_H_
#include <memory>
using std::unique_ptr;
using std::shared_ptr;
template <typename T>
class Node {
public:
    Node(T obj, shared_ptr<Node<T>> next)
        :obj(obj),next(next) {

    }
    Node(T obj)
        :Node(obj,nullptr){
    }
    T& get() {
        return obj;
    }
    shared_ptr<Node<T>>& getNext() {
        return next;
    }
    bool equals(shared_ptr<Node<T>>& other) {
        return equals(*other);
    }
    bool equals(Node& other) {
        return equals(other.obj);
    }
    bool equals(T& other) {
        return other == obj;
    }
    void setNext(shared_ptr<Node<T>>& next) {
        this -> next = next;
    }
private:
    shared_ptr<Node<T>> next;
    T obj;

};


#endif
