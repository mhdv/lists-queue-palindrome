#include<iostream>
#include<string>
#include<cstdlib>
#include"wezel.h"
#include"list.h"
#include"colors.h"


template<typename T>
MyList<T>::MyList() // konstruktor
    :head(NULL)    {}

template<typename T>
MyList<T>::~MyList() // destruktor
    {}

// DODAJE ELEMENT

template<typename T>
void MyList<T>::addFront(const T &e){
    MyNode<T>* v = new MyNode<T>; // tworzy wezel
    v->element = e; // instrukcje ustalajace kazdy nowy element na head
    v->next = head;
    head = v;
}

// USUWA ELEMENT GLOWY

template<typename T>
void MyList<T>::removeFront(){
    MyNode<T>* old = head; // wezel pomocniczy
    head = old->next;
    delete old; // usuwanie wezla pomocniczego
}

// ZWRACA PRAWDE JESLI LISTA JEST PUSTA

template<typename T>
bool MyList<T>::empty(){ // funkcja zwracajaca prawde jesli lista jest pusta
    if(head==NULL) return true;
    else return false;
}

// WYSWIETLA GLOWE LISTY

template<typename T>
void MyList<T>::displayHead(){ // wyswietla head
    std::cout << GREEN << head->getElement();
    std::cout << "\n";
}

// WYSWIETLA CALA ZAWARTOSC LISTY

template<typename T>
void MyList<T>::displayList(){ // wyswietla cala liste
    MyNode<T>* tmp = new MyNode<T>; // tworzy wezel pomocniczy
    tmp=head; // ustawia wezel pomocniczy na head naszej listy
    std::cout << "Oto Twoja aktualna lista:\n";
    do{
        std::cout << GREEN << tmp->getElement();
        tmp=tmp->getNext();
        std::cout << "\n";
    }while(tmp!=nullptr);
    delete tmp; // usuwa wezel pomocniczy
}

// TWORZONE SPECJALNIE NA POTRZEBY PERMUTACJI/PALINDROMOW USUWANIE

template<typename T>
void MyList<T>::deleteSame(){ // srednio dziala..
    MyNode<T>* tmp = new MyNode<T>;
    MyNode<T>* tmp2 = new MyNode<T>;
    MyNode<T>* tmp3 = new MyNode<T>;


//    tmp = head;
//    if(tmp==NULL) return;

//    while(tmp->getNext() != NULL){
//        if(tmp->getElement() == tmp->getNext()->getElement()){
//            tmp2 = tmp->getNext()->getNext();
//            MyList<T>::removeFront();
//            tmp->getNext() = tmp2;
//        }else{
//            tmp = tmp->getNext();
//        }
//    }
//    MyNode<T>* tmp3 = new MyNode<T>;

    do{
        tmp3=head;
        if(head!=tmp3){
        tmp = head;
        tmp2 = head->getNext();
        }else{
        tmp = tmp->getNext();
        tmp2 = tmp->getNext();
        }
//        do{
//            tmp = head->getNext();
//            if(tmp == head){
//                tmp2 = head;
//                MyList<T>::removeFront();
//                tmp = nullptr;
//            }
//            head = head->getNext();
//        }while(tmp!=nullptr);
        do{
            if(tmp==tmp2){
                MyList<T>::removeFront();
                tmp2 = head->getNext();
            }else{
                tmp2 = tmp2->getNext();
            }
        }while(tmp2!=nullptr);
//        tmp = tmp->getNext();
//        tmp2 = tmp->getNext();
    }while(tmp2!=nullptr);
    delete tmp;
    delete tmp2;
}





//########################
template class MyList<int>;
template class MyList<double>;
template class MyList<float>;
template class MyList<std::string>;
