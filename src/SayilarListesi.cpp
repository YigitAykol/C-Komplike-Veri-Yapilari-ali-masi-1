#include "SayilarListesi.hpp"
#include<iomanip>

void SayilarListesi::insertNewList()
{
    NodeSayilar* sayilar2 = new NodeSayilar();
     
    if (head == NULL)
    {
        head = sayilar2;
        return;
    }
    // Insert in the beginning of the list
    else {
        /*
            sayilar2->next = head;
            head = sayilar2;
            cout<<&*sayilar2<<"  "<<&*head<<"\n"; 
        */
        NodeSayilar* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = sayilar2;
        
     /**  
       NodeSayilar *a = head;
        while(a!= NULL)
        {
            a = a->next;
        }
        a=sayilar2;
        */
        
    }
    
}

void SayilarListesi::insertDigits(int n)
{
    
    //cout<<"  "<<n<<"\n";
    NodeSayilar* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->liste->insert(new Basamak(n));
    
} 
void SayilarListesi::findMaxNode()
{
     NodeSayilar* current = head;
     int y = current->liste->sum();
     int i=0;
    while (current->next != nullptr) {
        
        current = current->next;
        if(y>current->liste->sum())
        {
            y =  current->liste->sum();
            i++;
        }
    }

    cout<<i<<"     "<<y<<endl;
}

void SayilarListesi::removeMax()
{
    NodeSayilar* temp = head;
    int k=0;
    int swap=temp->liste->c;
    for(int i = 0; temp->next != NULL; ++i)
    {
        if((temp->next->liste->c)>swap)
        {
            swap=temp->next->liste->c;
            k=i;
        }
        temp = temp->next;
    }

    remove(k+1);

}

void SayilarListesi::printLists()
{
    cout<<" "<<"\n";
    NodeSayilar* temp = head;
    
    for(int i = 0; temp != NULL; ++i)
    {   
        if(temp->liste->a!=0)
        {
            //cout<<"##########   **************************************************************\n";
            cout<<"##########   ";
            for(int f=0; f<temp->liste->a; ++f)
            {
                cout<<"*************";
            }
            cout<<endl;
            //cout<<"##########    "<<setw(10) <<setfill('*')<<'\n';
            
            cout<<&*temp<<"   ";
        }
        
        //cout<<&temp->liste<<"\n";
        temp->liste->calculateSum();//************
        //if(temp->liste->c!=-1)
        temp->liste->printList();

        cout<<"\n";
        temp = temp->next;
    }
}

void SayilarListesi::moveOddDigitsToHead()
{
    NodeSayilar* current = head;
    while (current->next != nullptr) {
        current->liste->moveOddDigitToHead();
        current = current->next;
    }
}
void SayilarListesi::reverseNodes()
{
    NodeSayilar* current = head;
    while (current->next != nullptr) {
        current->liste->reverseNodes();
        current = current->next;
    } 
}

void SayilarListesi::deleteMax()
{
    NodeSayilar* current = head;
    while (current->next != nullptr) {
        current->liste->findMaxElment();
        current = current->next;
    } 
}

SayilarListesi::~SayilarListesi()
{
    //delete head;
    /**
     while (head != nullptr) {
        NodeSayilar* temp = head;
        head = head->next;
        delete temp;
    }*/
    NodeSayilar* current = head;
    NodeSayilar* next = NULL;
 
    while (current != NULL) 
    {
        next = current->next;
        free(current);
        current = next;
    }
}

void SayilarListesi::remove(int a)
{
    
    int currentPosition=0;
    if(head == NULL)
    {
        return;
    }

    if (a == 0) {

        NodeSayilar* temp = head;
        head = temp->next;

        delete temp;

        
        return;
    }

    NodeSayilar* current = head;
       
    std::cout << a << std::endl;
        
    while (current != nullptr && currentPosition < a-1) {
        current = current->next;
        currentPosition++;
    }
    if (current == nullptr || current->next == nullptr) {
        std::cout << "Position out of bounds. Cannot remove a node." << std::endl;
        return;
    }

    NodeSayilar* temp2 = current->next;
    current->next = current->next->next;
    delete temp2;

    std::cout << "Node at position " << a+1 << " removed." << std::endl;
}

void SayilarListesi::enterTheSum(int b, Sayi *ea)
{
    ea->printList();
    std::cout << "Node at position " << ea->retunSpecific(0)<< " yy." << std::endl;
    NodeSayilar* current = head;
    int k=0;
    while (current->next != nullptr) {
        current->sum=ea->retunSpecific(k);
        current = current->next;
        std::cout << "Node at position " << current->sum<< " yy." << std::endl;
        k++;
    }

    

    
    //std::cout << "Node at position " << current->sum << " removed." << std::endl;
    //current->liste->
    
    
    
    
}

void SayilarListesi::printSum()//delete empty nodes***************************
{
    /**
    cout<<"  "<<"\n";
    NodeSayilar* temp = head;
    for(int i = 0; temp != NULL; ++i)
    {
        //cout<<&temp->liste<<"\n";
        temp->liste->printList();
        //cout<<temp->liste->c<<"\n";
        temp = temp->next;
    }
    */
   

}

void SayilarListesi::enterTheSum2(int b)
{
    NodeSayilar* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->sum=b;
}