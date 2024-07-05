#include "Basamak.hpp"

Basamak::Basamak(int x)
{
    key = x;
    next = NULL;
}


Basamak::~Basamak()
{
    delete next;
}

