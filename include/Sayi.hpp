#ifndef Sayi_HPP
#define Sayi_HPP
/**
* @file Sayi.cpp
* @description Sayi sınıfının nodu u 
* @course 2A
* @assignment 1
* @date 7.11.2021
* @author Mahmut Yiğit
*/
#include "Basamak.hpp"
using namespace std;

class Sayi
{
    Basamak *head;
    //int a;
    //int c;
    

    public:
        Sayi();//create empty list
        int c;
        int a;
        
        int sum();
        int calculateSum();
        int retunSpecific(int k);
        void insert(Basamak* newNode);
        void moveOddDigitToHead();
        void reverseNodes();
        void printList();
        int findMaxElment();
        ~Sayi();

};
#endif