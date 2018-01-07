#include<iostream>
#include<string>
#include<cstdlib>
#include<stdio.h>
#include"wezel.h"
#include"list.h"
#include"queue.h"
#include"perpal.h"
#include"colors.h"

void ctc();                 //funkcja Click To Continue, wyswietla komunikat i czeka na getchar()
void optionexception();     //wyjatek gdy uzytkownik poda zly rodzaj zmiennej na strumien wejscia

int main()
{
    int option;             //zmienna odpowiadajaca za opcje w switchu (menu)
    do{
        std::cout << WHITE << "Witaj w programie PAMSI-2\n"
                  << GREEN << "Wybierz opcje i zatwierdz klawiszem ENTER.\n"
                  << "1) Wlasna implementacja list.\n"
                  << "2) Wlasna implementacja kolejek.\n"
                  << "3) Palindromy z permutacjami.\n"
                  << "0) Wyjdz z programu.\n";
        while(!(std::cin >> option) | (option > 3) | (option < 0)) optionexception();
        switch(option){
/*
###########  PROGRAM 1) LISTY ###############
*/
        case 1:
        {
            MyList<int>* lista = new MyList<int>;       //tworzy nowy obiekt listy
            do{
                system("clear");
                std::cout << WHITE << "Witaj we wlasnej implementacji list.\n"
                          << GREEN << "Wybierz opcje i zatwierdz klawiszem ENTER.\n"
                          << "1) Dodaj element do listy.\n"
                          << "2) Usun element z listy.\n"
                          << "3) Wyswietl pelna zawartosc listy.\n"
                          << "4) Usun liste.\n"
                          << "0) Cofnij.\n";
                while(!(std::cin >> option) | (option > 4) | (option < 0)) optionexception();
                switch(option){
                case 1:
                {
                    system("clear");
                    std::cout << GREEN << "Podaj liczbe (domyslnie integer).\n";
                    int nowy;
                    while(!(std::cin >> nowy)) optionexception();
                    lista->addFront(nowy);
                    std::cout << RED << "Pomyslnie dodano element!\n";
                    ctc();
                    break;
                }
                case 2:
                {
                    if(lista->empty()==0){
                        lista->removeFront();
                        std::cout << RED << "Pomyslnie usunieto element.\n";
                    }else{
                        std::cout << RED << "Nie ma zadnego elementu!\n";
                    }
                    ctc();
                    break;
                }
                case 3:
                {
                    if(lista->empty()==0){
                        system("clear");
                        lista->displayList();
                        getchar();getchar();
                    }else std::cout << RED << "Lista jest pusta!\n";
                    ctc();
                    break;
                }
                case 4:
                {
                    if(lista->empty()==0){
                        delete lista;
                        MyList<int>* lista = new MyList<int>;
                        std::cout << RED << "Pomyslnie usunieto liste!\n";
                    }else std::cout << RED << "Nie ma zadnej listy.\n";
                    ctc();
                    break;
                }
                default:
                    break;
                }
            }while(option!=0);
            option=-1;
            delete lista;
            system("clear");
            break;
        }
/*
############ PROGRAM 2) KOLEJKI #############
*/
        case 2:
        {
            MyQueue<int>* kolejka = new MyQueue<int>;       //tworzy nowy obiekt kolejki
            do{
                system("clear");
                std::cout << WHITE << "Witaj we wlasnej implementacji kolejek.\n"
                          << GREEN << "Wybierz opcje i zatwierdz klawiszem ENTER.\n"
                          << "1) Dodaj element do kolejki.\n"
                          << "2) Usun element z kolejki.\n"
                          << "3) Wyswietl pelna zawartosc kolejki.\n"
                          << "4) Usun kolejke.\n"
                          << "0) Cofnij.\n";
                while(!(std::cin >> option) | (option > 4) | (option < 0)) optionexception();
                switch(option){
                case 1:
                {
                    system("clear");
                    std::cout << GREEN << "Podaj liczbe (domyslnie integer).\n";
                    int nowy;
                    while(!(std::cin >> nowy)) optionexception();
                    kolejka->addEnd(nowy);
                    std::cout << RED << "Pomyslnie dodano element!\n";
                    ctc();
                    break;
                }
                case 2:
                {
                    if(kolejka->empty()==0){
                        kolejka->removeFront();
                        std::cout << RED << "Pomyslnie usunieto element.\n";
                    }else{
                        std::cout << RED << "Nie ma zadnego elementu!\n";
                    }
                    ctc();
                    break;
                }
                case 3:
                {
                    if(kolejka->empty()==0){
                        system("clear");
                        kolejka->displayQueue();
                        getchar();getchar();
                    }else std::cout << RED << "Kolejka jest pusta!\n";
                    ctc();
                    break;
                }
                case 4:
                {
                    if(kolejka->empty()==0){
                        delete kolejka;
                        MyQueue<int>* kolejka = new MyQueue<int>;
                        std::cout << RED << "Pomyslnie usunieto Kolejke!\n";
                    }else std::cout << RED << "Nie ma zadnej kolejki.\n";
                    ctc();
                    break;
                }
                default:
                    break;
                }
            }while(option!=0);
            option=-1;
            delete kolejka;
            system("clear");
            break;
        }
/*
############ PROGRAM 3) PERMUTACJE #############
*/
        case 3:
        {
            PerPal permut;       //tworzy nowy obiekt permutacji/palindromu
            do{
                system("clear");
//                permut.zapisaneSlowo();
                std::cout << WHITE << "Witaj w wykrywaniu palindromow w permutacji ciagu znakow.\n"
                          << GREEN << "Wybierz opcje i zatwierdz klawiszem ENTER.\n"
                          << "1) Wprowadz slowo.\n"
                          << "2) Permutuj i zapisz palindromy.\n"
                          << "3) Wyswietl zapisane palindromy.\n"
                          << "4) Usun powtorki palindromow.\n"
                          << "0) Cofnij.\n";
                while(!(std::cin >> option) | (option > 4) | (option < 0)) optionexception();
                switch(option){
                case 1:
                {
                    system("clear");
                    std::cout << "Podaj slowo/ciag znakow:\n";
                    std::string slowko;
                    std::cin.ignore();
                    std::cin.clear();
                    std::getline (std::cin, slowko);
                    permut.wprowadzSlowo(slowko);
                    ctc();
                    break;
                }
                case 2:
                {
                    system("clear");
                    if(permut.isEmpty()==0){
                        permut.permutacja(0);
                        std::cout << GREEN << "Poprawnie zapisano palindromy.\n";
                    }else{
                        std::cout << RED << "Nie masz zapisanego slowa.\n";
                    }
                    ctc();
                    break;
                }
                case 3:
                {
                    system("clear");
                    if(permut.isEmpty()==0){
                        permut.wyswietlPermutacje();
                    }else{
                        std::cout << RED << "Nic nie zostalo zapisane.\n";
                    }
                    ctc();
                    break;
                }
                case 4:
                {
                    system("clear");
                    if(permut.permutacje->empty()==0){
                        permut.usunPowtorki();
                    }else{
                        std::cout << RED << "Nic nie zostalo zapisane.\n";
                    }
                    ctc();
                    break;
                }
                default:
                    break;
                }
            }while(option!=0);
            option=-1;
            system("clear");
            break;
        }
        }
    }while(option!=0);



    std::cout << WHITE;
    return 0;
}

void optionexception(){
    std::cin.clear(); std::cin.ignore();
    std::cout << RED << "UPS! Wpisales zly symbol, wybierz poprawna cyfre.\n" << GREEN;
}

void ctc(){
    std::cout << GREEN << "Kliknij ENTER aby kontynuowac.\n";
    getchar();getchar();
}
