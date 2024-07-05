#ifndef SayilarListesi_HPP
#define SayilarListesi_HPP
#include "NodeSayilar.hpp"
/**
* @file SayilarListesi.cpp
* @description SayiListesi sayıların hepsini tutar
* @course 2A
* @assignment 1
* @date 7.11.2021
* @author Mahmut Yiğit
*/


 class SayilarListesi{

    NodeSayilar* head;
    
    public:
        SayilarListesi()
        {
            head = new NodeSayilar();
        }

        void insertNewList();
        void insertDigits(int n);
        void printLists();
        void moveOddDigitsToHead();
        void reverseNodes();
        void deleteMax();
        ~SayilarListesi();
        void enterTheSum(int b, Sayi *ea);
        void enterTheSum2(int b);
        void findMaxNode();
        void remove(int a);
        void printSum();
        void removeMax();
 };



#endif