#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
/**
* @file Basamak.cpp
* @description Basamak sınıfı Sayinin nodudur.
* @course 2A
* @assignment 1
* @date 7.11.2021
* @author Mahmut Yiğit
*/
class Basamak{
    public:
    
    int key;
    Basamak* next;
 
    Basamak(int n);
    ~Basamak();
    
};



#endif