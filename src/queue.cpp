#include<iostream>
#include<string>
#include<cstdlib>
#include"wezel.h"
#include"queue.h"
#include"colors.h"


template<typename T>
MyQueue<T>::MyQueue() // konstruktor
    :head(NULL)
    ,tail(NULL)     {}

template<typename T>
MyQueue<T>::~MyQueue() // destruktor
    {}

// DODAJE ELEMENT NA KONIEC

template<typename T>
void MyQueue<T>::addEnd(const T &e){
    MyNode<T>* v = new MyNode<T>;
    v->element = e;
    v->next = nullptr;
    if(head==nullptr) head = v;
    else tail->next = v;
    tail = v;
}

// USUWA ELEMENT Z POCZATKU

template<typename T>
void MyQueue<T>::removeFront(){
    MyNode<T>* old = head;
    head = old->next;
    delete old;
}

// SPRAWDZA CZY KOLEJKA JEST PUSTA

template<typename T>
bool MyQueue<T>::empty(){
    if(head==NULL) return true;
    else return false;
}

// WYSWIETLA HEAD

template<typename T>
void MyQueue<T>::displayHead(){
    std::cout << GREEN << head->getElement();
    std::cout << "\n";
}

// WYSWIETLA OGON

template<typename T>
void MyQueue<T>::displayTail(){
    std::cout << GREEN << tail->getElement();
    std::cout << "\n";
}

// WYSWIETLA KOLEJKE

template<typename T>
void MyQueue<T>::displayQueue(){
    MyNode<T>* tmp = new MyNode<T>;
    tmp=head;
    std::cout << "Oto Twoja aktualna kolejka:\n";
    do{
        std::cout << GREEN << tmp->getElement();
        tmp=tmp->getNext();
        std::cout << "\n";
    }while(tmp!=nullptr);
    delete tmp;
}





//############################
template class MyQueue<int>;
template class MyQueue<double>;
template class MyQueue<float>;
