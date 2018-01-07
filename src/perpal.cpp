#include<iostream>
#include<string>
#include<cstdlib>
#include"wezel.h"
#include"list.h"
#include"perpal.h"
#include"colors.h"

PerPal::PerPal() // konstruktor
    :index(0)   {}

// ZAPISUJE SLOWO

void PerPal::wprowadzSlowo(std::string palindrom){
    slowo = palindrom; // ustawia podane slowo
    permutacje = new MyList<std::string>;
}

// SPRAWDZA CZY SLOWO JEST PALINDROMEM

int PerPal::jestPal(std::string palindrom, int pocz, int kon){ // rekurencyjne sprawdzanie czy slowo jest palindromem
    if(palindrom[pocz]==palindrom[kon]) return jestPal(palindrom, pocz+1, kon-1);
    if(pocz>kon){
        return 1;
    }
    else{
        return 0;
    }
}

// TWORZY WSZYSTKIE MOZLIWE PERMUTACJE

void PerPal::permutacja(int ind){
    index = ind;
    if(index < slowo.size()-1){
        for(int i=index; i < slowo.size()-1; i++){
            PerPal::swap(slowo[index], slowo[i]); // zamienia znaki stringa
            PerPal::permutacja(ind+1); // wywoluje sama siebie (rekurencja)
            PerPal::swap(slowo[index], slowo[i]); // powrot
        }
    }
    else{
            std::cout << WHITE << slowo;
            PerPal::wyswietlPal(slowo);
            std::cout << "\n";
    }
}

// WYSWIETLA PERMUTACJE

void PerPal::wyswietlPal(std::string palindrom){ // wyswietla palindrom
    if(PerPal::jestPal(palindrom, 0, palindrom.size()-1)==1){
        std::cout << "   Twoje slowo jest palindromem.\n";
        permutacje->addFront(palindrom);
    }else{
        std::cout << "   Twoje slowo nie jest palindromem.\n";
    }
}

// ZAMIENIA LITERY...

void PerPal::swap(char &a, char &b){
    char c=a; a=b; b=c;
}

// WYSWIETLA ZAPISANE SLOWO

void PerPal::zapisaneSlowo(){
    if(!slowo.empty()) std::cout << GREEN << "Zapisane slowo to: " << BLUE << slowo << "\n";
    else std::cout << RED << "Nie masz zapisanego slowa.\n" << GREEN;
}

// ZWRACA PRAWDE JESLI NIE ZAPISANO SLOWA

bool PerPal::isEmpty(){
    if(!slowo.empty()) return 0;
    else return 1;
}

// WYSWIETLA PALINDROMY

void PerPal::wyswietlPermutacje(){
    if(permutacje->empty()==0) permutacje->displayList();
    else std::cout << RED << "Nie znaleziono zadnych palindromow.\n";
}

// WYWOLUJE FUNKCJE USUWANIA POWTOREK

void PerPal::usunPowtorki(){ // w zamysle mialo usuwac powtorki..
    permutacje->deleteSame();
}
