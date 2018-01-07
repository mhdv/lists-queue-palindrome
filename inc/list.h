#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<string>
#include<cstdlib>

class PerPal;
template <typename T>
class MyQueue;
template <typename T>
class MyNode;
template <typename T>

// opisy w pliku .cpp

class MyList{
public:
    MyList();
    ~MyList();
    bool empty();
    void displayList();
    void displayHead();
    void addFront(const T& e);
    void removeFront();
    void deleteSame();
    friend class PerPal;
private:
    MyNode<T>* head;
};


#endif // LIST_H
