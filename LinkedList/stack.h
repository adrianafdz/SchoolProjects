#ifndef STACK_H
#define STACK_H
#include "node.h"

template<class T>
class stack
{
    public:
        stack();
        ~stack();
        void push(T data);
        void pop();
        bool empty();
        int size();
        T top();

    private:
        node<T> *tope;
        int tam;
};

template <class T>
stack<T>::stack(){
    tope = nullptr;
    tam = 0;
}

template <class T>
stack<T>::~stack() {
    node<T> *curr = tope;
    while (tope!=nullptr) {
        tope = tope->getNext();
        delete curr;
        curr = tope;
    }
}

template <class T>
void stack<T>::push(T data) {
    tope = new node<T>(data, tope);
    tam++;
}

template <class T>
void stack<T>::pop() {
    node<T> *curr = tope;
    tope = tope->getNext();
    delete curr;
    tam--;
}

template <class T>
bool stack<T>::empty() {
    return tope==nullptr;
}

template <class T>
int stack<T>::size(){
    return tam;
}

template <class T>
T stack<T>::top() {
    return tope->getData();
}

#endif // STACK_H
