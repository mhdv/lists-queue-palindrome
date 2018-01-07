#ifndef PERPAL_H
#define PERPAL_H

#endif // PERPAL_H

#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>

template <typename T>
class MyQueue;
template <typename T>
class MyNode;
template <typename T>
class MyList;

// opisy w pliku .cpp

class PerPal{
public:
    PerPal();
    MyList<std::string>* permutacje;
    void wprowadzSlowo(std::string palindrom);
    int jestPal(std::string palindrom, int pocz, int kon);
    void permutacja(int ind);
    void swap(char &a, char &b);
    void zapisaneSlowo();
    void wyswietlPal(std::string palindrom);
    bool isEmpty();
    void wyswietlPermutacje();
    void usunPowtorki();
    std::string slowko() {return slowo;}
private:
    std::string slowo;
    int index;
};
