#ifndef QUEUE_H
#define QUEUE_H


#include<iostream>
#include<string>
#include<cstdlib>

class PerPal;
template <typename T>
class MyList;
template <typename T>
class MyNode;
template <typename T>

// opisy w pliku .cpp

class MyQueue{
public:
    MyQueue();
    ~MyQueue();
    bool empty();
//    const T& front() { return head;}
    void displayQueue();
    void displayHead();
    void displayTail();
    void addEnd(const T& e);
    void removeFront();
private:
    MyNode<T>* head;
    MyNode<T>* tail;
};


#endif // QUEUE_H
