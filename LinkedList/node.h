#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <class T>
class node {
public:
    node(T data);
    node(T data, node<T> *next);
    T getData();
    node<T>* getNext();
    void setData(T data);
    void setNext(node<T> *next);

    int getCounter() {return counter;}
    void increaseCounter() {counter++;}
private:
    T data;
    node<T> *next;

    int counter=0;
};

template <class T>
node<T>::node(T data) {
    this->data = data;
    this->next = nullptr;
}

template <class T>
node<T>::node(T data, node<T> *next) {
    this->data = data;
    this->next = next;
}

template <class T>
T node<T>::getData() {
    return data;
}

template <class T>
node<T>* node<T>::getNext() {
    return next;
}

template <class T>
void node<T>::setData(T data) {
    this->data = data;
}

template <class T>
void node<T>::setNext(node <T>* next) {
    this->next = next;
}
#endif // NODE_H_INCLUDED
