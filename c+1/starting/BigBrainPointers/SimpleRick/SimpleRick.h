#ifndef _SIMPLERICK_H_
#define _SIMPLERICK_H_


template <typename T>
class SimpleRick {
public:
	SimpleRick();
	SimpleRick(T * point);
	T & operator*();
	T * operator->();
	~SimpleRick();
private:
	T *p;
};
template <typename T>
SimpleRick<T>::SimpleRick(T *point)
	:p(point) {
}


template <typename T>
T & SimpleRick<T>::operator*() {

	return *p;

}

template <typename T>
T * SimpleRick<T>::operator->() {
	return p;
}
template <typename T>
SimpleRick<T>::SimpleRick()
	:p(nullptr){
}
template <typename T>
SimpleRick<T>::~SimpleRick() {
	delete p;
}
#endif
