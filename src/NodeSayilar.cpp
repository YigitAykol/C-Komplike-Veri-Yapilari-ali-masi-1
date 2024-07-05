#include "NodeSayilar.hpp"

NodeSayilar::NodeSayilar()
{
    liste= new Sayi();//liste=NULL  new Sayi()
    //sum=0;
    next=NULL;
}

NodeSayilar::~NodeSayilar()
{
    delete liste;
    //delete next;
}

void NodeSayilar::listeyeEkle(int c)// linked liste ye ulaş 
{
    sum=c;

}

