#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "node.h"

template <class T>
class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		bool isEmpty();
		int getSize();
		void addFirst(T data);
		void addLast(T data);
		bool add(T data, int pos);
		void deleteFirst();
		void deleteLast();
		void del(int pos);
		int deleteAll();
		T get(int pos);
		T set(T data, int pos);
		bool change(int pos1, int pos2);
		void print();
		// TAREA
        void reverse();
        void shift(int cant);
        void spin(int cant);
        bool operator==(const LinkedList<T> &otra);
        void operator+=(T data);
        void operator+=(const LinkedList<T> &otra);
        LinkedList(const LinkedList<T> &otra);
        void operator=(const LinkedList<T> &otra);
        //EXAMEN
        LinkedList<T> split (int n);
        bool check();

        void addCount(int n);
        int biggestCount(int &datoMayor);

        void printReverse();
        void reverseRec();

	private:
		node<T> *head;
		int size;
		void borraTodo();
		void printRevRec(node<T>* curr);
		void revRec(node<T>* curr);
};

template <class T>
LinkedList<T>::LinkedList(){
	head = nullptr;
	size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
	borraTodo();
}

template <class T>
void LinkedList<T>::borraTodo(){
	node<T> *curr = head;
	while (head != nullptr){
		head = head->getNext();
		delete curr;
		curr = head;
		size--;
	}
}

template <class T>
bool LinkedList<T>::isEmpty(){
	return (head == nullptr);
}

template <class T>
int LinkedList<T>::getSize(){
	return size;
}

template <class T>
void LinkedList<T>::addFirst(T data){
	head = new node<T>(data, head);
	head->increaseCounter();
	size++;
}

template <class T>
void LinkedList<T>::addLast(T data){
	if (size == 0){
		addFirst(data);
	}
	else{
		node<T> *curr = head;
		while (curr->getNext() != nullptr){
			curr = curr->getNext();
		}
		curr->setNext(new node<T>(data));
		size++;
		curr->getNext()->increaseCounter();
	}
}

template <class T>
void LinkedList<T>::addCount(int n) {
    if (head!=nullptr) {
        node<T> *curr = head;
        if (head->getData()==n) {
            head->increaseCounter();
            return;
        }
        while (curr->getNext() != nullptr) {
            if (n == curr->getData()) {
                curr->increaseCounter();
                return;
            }
            curr = curr->getNext();
        }
        // SI NO LO ENCUENTRA, LO AGREGA AL FINAL
        curr->setNext(new node<T>(n));
        curr->getNext()->increaseCounter();
        return;
    } else {
        addFirst(n);
    }
}

template <class T>
int LinkedList<T>::biggestCount(int &datoMayor) {
    if (head!=nullptr) {
        node<T> *curr = head;
        int mayor = head->getCounter();
        datoMayor = head->getData();
        while (curr->getNext() != nullptr){
            curr = curr->getNext();
            if (mayor<=curr->getCounter()){
                mayor=curr->getCounter();
                datoMayor=curr->getData();
            }
        }
        return mayor;
    }
    // contador mayor
    return -1;
}

template <class T>
bool LinkedList<T>::add(T data, int pos){
	if (pos > size){
		return false;
	}
	if (pos == 0){
		addFirst(data);
	}
	else if (pos == size){
		addLast(data);
	}
	else {
		node<T> *curr = head;
		for (int i=1; i<pos; i++){
			curr = curr->getNext();
		}
		curr->setNext(new node<T>(data, curr->getNext()));
		size++;
	}
	return true;
}

template <class T>
void LinkedList<T>::deleteFirst(){
	if (!isEmpty()){
		node<T> *curr = head;
		head = head->getNext();
		delete curr;
		size--;
	}
}

template <class T>
void LinkedList<T>::deleteLast(){
	if (size <= 1){
		deleteFirst();
	}
	else{
		node<T> *curr = head;
		while (curr->getNext()->getNext() != nullptr){
			curr = curr->getNext();
		}
		delete curr->getNext();
		curr->setNext(nullptr);
		size--;
	}
}

template <class T>
void LinkedList<T>::del(int pos){
	if (pos == 0){
		deleteFirst();
	}
	else{
		node<T> *curr = head;
		for (int i=1; i<pos; i++){
			curr = curr->getNext();
		}
		node<T> *aux = curr->getNext();
		curr->setNext(aux->getNext());
		delete aux;
		size--;
	}
}

template <class T>
int LinkedList<T>::deleteAll(){
	borraTodo();
	int auxSize = size;
	size = 0;
	return auxSize;
}

template <class T>
T LinkedList<T>::get(int pos){
	node<T> *curr = head;
	for (int i=1; i<=pos; i++){
		curr = curr->getNext();
	}
	return curr->getData();
}

template <class T>
T LinkedList<T>::set(T data, int pos){
	node<T> *curr = head;
	for (int i=1; i<=pos; i++){
		curr = curr->getNext();
	}
	T dataAux = curr->getData();
	curr->setData(data);
	return dataAux;
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2){
	if (pos1 < 0 || pos2 < 0 || pos1 >= size || pos2 >= size){
		return false;
	}
	if (pos1 == pos2){
		return true;
	}
	int posMen = (pos1 < pos2 ? pos1 : pos2);
	int posMay = (pos1 > pos2 ? pos1 : pos2);
	node<T> *curr1 = head;
	for (int i=1; i<=posMen; i++){
		curr1 = curr1->getNext();
	}
	node<T> *curr2 = curr1;
	for (int i=posMen; i<posMay; i++){
		curr2 = curr2->getNext();
	}
	T dataAux = curr1->getData();
	curr1->setData(curr2->getData());
	curr2->setData(dataAux);
	return true;
}

template <class T>
void LinkedList<T>::print(){
	node<T> *curr = head;
	while (curr != nullptr){
		cout << curr->getData() << ", counted: " << curr->getCounter()<<endl;
		curr = curr->getNext();
	}
}

template <class T>
void LinkedList<T>::reverse(){
    if (size>1){
        node<T> *prev = nullptr;
        node<T> *next = head;
        while (head != nullptr) {
            next = next->getNext();
            head->setNext(prev);
            prev = head;
            head = next;
        }
        head = prev;
    }
}

template <class T>
void LinkedList<T>::shift(int cant){
    cant=cant%size;
    if (cant!=0) {
        node<T> *curr = head;
        if (cant>0) {
            cant=size-cant;
        } else {
            cant*=-1;
        }
        while (curr->getNext() != nullptr){
            curr = curr->getNext();
        }
        curr->setNext(head);
        for (int i=1; i<=cant; i++) {
            head=head->getNext();
            curr=curr->getNext();
        }
        curr->setNext(nullptr);
    }
}

template <class T>
void LinkedList<T>::spin(int cant){
    if (cant>=size) {
        reverse();
    } else if (cant>1) {
        // PRIMERA PARTE USANDO EL HEAD
        node<T> *last=head;
        node<T> *prev=head;
        node<T> *next=head->getNext();
        for (int i=0; i<cant-1; i++) {
            head=next;
            next=next->getNext();
            head->setNext(prev);
            prev=head;
        }
        last->setNext(next);

        // PARTE DE ENMEDIO
        node<T> *prevLast;
        node<T>* curr;
        int mod=(size/cant)-1;

        for(int i=0; i<mod; i++) {
            prevLast=last;
            last=next;
            prev=next;
            curr=next;
            next=next->getNext();

            for (int j=0; j<cant-1; j++) {
                curr=next;
                next=next->getNext();
                curr->setNext(prev);
                prev=curr;
            }

            prevLast->setNext(curr);
            last->setNext(next);
        }

        // SECCION FINAL
        if (size%cant>1) {
            prevLast=last;
            last=next;
            prev=next;
            curr=next;
            next=next->getNext();

            while (next!=nullptr) {
                curr=next;
                next=next->getNext();
                curr->setNext(prev);
                prev=curr;
            }

            prevLast->setNext(curr);
            last->setNext(next);
        }
    }
}

template <class T>
bool LinkedList<T>::operator==(const LinkedList<T> &otra) {
    if (size != otra.size) {
        return false;
    }
    node<T> *curr1 = head;
    node<T> *curr2 = otra.head;
    for (int i=1; i<=size; i++) {
        if (curr1->getData() != curr2->getData()) {
            return false;
        }
        curr1 = curr1->getNext();
        curr2 = curr2->getNext();
    }
    return true;
}

template <class T>
void LinkedList<T>::operator+=(T data) {
    addLast(data);
}

template <class T>
void LinkedList<T>::operator+=(const LinkedList<T> &otra){
    if (otra.size == 1) {
        addLast(otra.head->getData());
    }
    if (otra.size > 1) {
        node<T> *currCopia = otra.head;
        if (head==nullptr){
            addFirst(currCopia->getData());
            currCopia=currCopia->getNext();
        }
        node<T> *curr = head;
        // final de primera lista
        while (curr->getNext() != nullptr){
			curr = curr->getNext();
		}
        // Agrega los elementos de la otra lista
        while (currCopia != nullptr) {
            curr->setNext(new node<T>(currCopia->getData()));
            size++;
            currCopia = currCopia->getNext();
            curr=curr->getNext();
        }

    }
}

template <class T>
void LinkedList<T>::operator=(const LinkedList<T> &otra){
    if (!(*this==otra)) {
        if (!isEmpty()) {
            this->borraTodo();
        }
        *this+=otra;
    }
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &otra){
    head = nullptr;
    *this+=otra;
}

template <class T>
LinkedList<T> LinkedList<T>::split(int n){
    LinkedList<T> nueva;
    if (n==0) {
        nueva.head=head;
        nueva.size=size;
        head=nullptr;
    }
    if (n>0 && n<size) {
        node<T>* curr=head;
        node<T> *inicio;
        for (int i=0; i<n-1; i++) {
            curr=curr->getNext();
        }
        inicio=curr->getNext();
        curr->setNext(nullptr);
        nueva.head=inicio;
    }
    nueva.size=size-n;
    size=n;
    return nueva;
}

template <class T>
bool LinkedList<T>::check() {
    int cont=0;
    if (head!=nullptr) {
        node<T> *curr=head;
        while (curr->getNext()!=nullptr) {
            cont++;
            curr=curr->getNext();
        }
        cont++;
    }
    return (cont==size);
}

template <class T>
void LinkedList<T>::printRevRec(node<T>* curr) {
    if (curr==nullptr) {
        cout<<endl;
        return;
    }
    printRevRec(curr->getNext());
    cout<<curr->getData()<<" ";
}

template <class T>
void LinkedList<T>::printReverse() {
    printRevRec(head);
}

template <class T>
void LinkedList<T>:: revRec(node<T>* curr) {
    if (curr->getNext() == nullptr) {
        // llego al ultimo node
        head = curr;
        return;
    }
    revRec(curr->getNext());

    // change links
    node<T> next = curr->getNext();
    next.setNext(curr);
    curr.setNext(nullptr);
}


template <class T>
void LinkedList<T>::reverseRec() {
    revRec(head);
}


#endif // LINKEDLIST_H_INCLUDED
