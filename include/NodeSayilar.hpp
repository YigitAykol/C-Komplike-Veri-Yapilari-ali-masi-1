#ifndef NodeSayilar_HPP
#define NodeSayilar_HPP
#include <iostream>
#include "Sayi.hpp"
/**
* @file NodeSayilar.cpp
* @description NodeSayilar sınıfı SayilarListesinin Nodedur.
* @course 2A
* @assignment 1
* @date 7.11.2021
* @author Mahmut Yiğit
*/
class NodeSayilar{
    public:
    
    Sayi* liste;//item 
    NodeSayilar* next;
    int sum;
    
 
    NodeSayilar();
    ~NodeSayilar();
    void listeyeEkle(int c);
};



#endif