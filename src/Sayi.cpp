#include "Sayi.hpp"
#include <math.h>
#include <sstream>
#include<iomanip>
Sayi::Sayi()
{
    head = NULL;
    a=0;
    
    c=-1;
}
Sayi::~Sayi()
{
    
    Basamak* current = head;
    Basamak* next = NULL;
 
    while (current != NULL) 
    {
        next = current->next;
        free(current);
        current = next;
    }
 
   
    
}

void Sayi::insert(Basamak* n)
{
    a++;
    
    // Bos ise
    if (head == NULL)
        head = n;
 
    // Basa ekle
    else {
       
        Basamak* temp= head;

        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next =n;
    }
}

int Sayi::sum()
{
    Basamak* temp= head;
    int sum=0;
    while(temp->next!=NULL)
    {
        sum += temp->key;
        temp = temp->next;
    }
    //cout<<sum<<"hehehmingw32-n    ";
    a=sum;

    return a;
}
int Sayi::calculateSum(){

    Basamak* ptr = head;
    double toplam=0;
    int e=a;

    
    
    while (ptr) {
        //cout << ptr->key << " -> ";
        if(e!=1)
        {
            toplam += ptr->key * pow(10,e-1);
        }
        else{

            toplam+=ptr->key;
        }
        //cout <<"    " <<toplam << endl;
        
        e--;
        ptr = ptr->next;
        
    }
    //cout << "NULL"<<toplam<<"    " <<a<< endl;
    c=toplam;

    return 0;
}

void printAdress(Basamak* ptr)
{
    Basamak* ptr2 = ptr;
     while (ptr2) {
       
        
       //cout <<"  " <<std::hex << (reinterpret_cast<int>(*&ptr2) % 1000);
       //cout <<"  " <<std::hex << addressString;
       
       cout <<"   " <<*&ptr2;
       //cout <<"   " <<*&ptr2;
       //cout<< setw(3) <<setfill(' ')<<*&ptr2;
        //setw(15-a) <<setfill(' ')
       

        ptr2 = ptr2->next;
     }
}

void Sayi::printList()
{
    Basamak* ptr = head;
    double toplam=0;
    int e=a;
    bool l=false;
    //cout<<"*** *** *** ***"<<'\n';
    while (ptr) {
        
        if(toplam==0)
        {
            //cout <<"      " <<std::hex << (uintptr_t)&*ptr % 1000;
            //cout <<"      " <<std::hex << (uintptr_t)&*ptr % 1000;
            printAdress(ptr);
            cout <<"    " << endl;
            //(uintptr_t)&*ptr % 1000;
        }
        if(l==false)
        {
            cout<<c;
            //cout <<"       ";
            cout <<setw(20-a) <<setfill(' ');


            l=true;
        }
        
        //cout  <<"  "<<ptr->key << "     *  ";
        //cout  << setw(15) <<setfill(' ')<<ptr->key << "  *  ";
        cout  <<ptr->key << "     *     ";
        
        if(e!=1)
        {
            toplam += ptr->key * pow(10,e-1);
        }
        else{

            toplam+=ptr->key;
        }
        //cout <<"    " <<toplam << endl;
        
        e--;
        ptr = ptr->next;
        
    }
    //calculateSum();
    //cout << "NULL"<<toplam<<"    " <<a<< endl;
    //cout << endl;
}

void Sayi::moveOddDigitToHead()
{
    
    if(head==nullptr|| head->next == nullptr) {
        // No need to move Basamaks if the list is empty or has only one Basamak
        return;
    }

    Basamak* current = head;
    Basamak* prev = nullptr;
    Basamak* oddDigitHead = nullptr;
    Basamak* oddDigitTail = nullptr;

    while (current != nullptr) {
        Basamak* nextBasamak = current->next;

        
        if (current->key % 2 != 0) {//basamak tek mi cift mi
            if (oddDigitHead == nullptr) 
            {
                // ilk tek yakaladım gunceleme yap
                oddDigitHead = current;
                oddDigitTail = current;
            } else {
                
                oddDigitTail->next = current;
                oddDigitTail = current;
            }

           
            if (prev != nullptr) {
                prev->next = nextBasamak;
            } else {
                
                head = nextBasamak;
            }

          
            current->next = nullptr;
        } else {
            
            prev = current;
        }

        
        current = nextBasamak;
    }

    
    if (oddDigitHead != nullptr) {
        oddDigitTail->next = head;
        head = oddDigitHead;
    }
}
void Sayi::reverseNodes()
{
    Basamak* prev = nullptr;
    Basamak* current = head;
    Basamak* nextBasamak = nullptr;

    while (current != nullptr) {
        nextBasamak = current->next;  // sonrakini kaydet

        

        // ters sevir
        current->next = prev;

        
        prev = current;
        current = nextBasamak;
    }

   
    head = prev;
}

int Sayi::findMaxElment()
{
    if (head == nullptr) {
        
        return 0; // Assuming the data type is int
    }
    else{
        Basamak* current = head;
        Basamak* max;
        int position = 0;
        int position2 = 0;
        int maxElement = current->key;

        while (current != nullptr) {
        if (current->key > maxElement) {
            maxElement = current->key;
            max=current;
            //position++;
            position=  position2;
        }
            current = current->next;
            position2++;
        }

        cout<< "  asd  " <<position<< "  asd  "<<maxElement<<"  asd  "<< endl;
        // sil basamak
        

        if(position == 0)//if(max == head)
        {
            Basamak* currentHead = head;
            Basamak* nextBasamak = head->next;

           
            head = nextBasamak;

            currentHead->next = nextBasamak->next;
            nextBasamak->next = currentHead;
        }

        Basamak* temp = head;
        for(int i = 0; temp != NULL && i < position - 1; i++)//for (int i = 0; temp != max ; i++)  (int i = 0; temp != NULL&&temp!=max ; i++)
            temp = temp->next;
        
        Basamak* next = temp->next->next;
 
        
        free(temp->next); 
        temp->next = next;

        return maxElement;
        
    }
}

int Sayi::retunSpecific(int k)
{
    Basamak* current = head;
    int currentPosition = 0;
    cout<< "  asd  " <<current->key<<"  asd  "<< endl;
    while (current != nullptr && currentPosition < k) {
        current = current->next;
        currentPosition++;
    }

    if (current != nullptr) {
        cout<< "  asd  " <<current->key<<"  asd  "<< endl;
        return current->key; //
    } else {
        // Handle the case where the position is out of bounds
        std::cerr << "Error: Position out of bounds." << std::endl;
        return -1; 
    }
}

