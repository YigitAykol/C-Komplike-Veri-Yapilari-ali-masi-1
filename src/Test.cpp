#include "Sayi.hpp"
#include "SayilarListesi.hpp"
#include <fstream>
#include <string>
#include <stdlib.h>
/**
* @file Test.cpp
* @description Main 
* @course 2A
* @assignment 1
* @date 7.11.2021
* @author Mahmut Yiğit
*/



int main(){
	Sayi* l1 = new Sayi();
	SayilarListesi* l2 = new SayilarListesi();
	
	ifstream myfile ("Sayilar.txt");
	string myline;
	int k=0;
	int m2=0;
	

	//l2->insertNewList();
	if ( myfile.is_open() ) { // always check whether the file is open
	
		while ( std::getline (myfile, myline) ) {
		
			//sayilariAyirma(myline, l1, l2);
			

			for(int i = 0; i<myline.length(); ++i)
			{
				char c = myline[i];
				int c1 = c -'0';
				//cout <<myline<<'\n';

				if(myline[i]==' ')// it means new number and new Sayi
				{
					//cout <<"beyaz\n";
					l2->insertNewList();
					m2++;
					 
				}
				else {
					l2->insertDigits(c1);
					
					
				}
			}
			
			l2->insertNewList();

			
			
			
		//cout << myline << ": " << myfile.tellg() << '\n';
		k++;
		}
		
	}
	myfile.close();
	
	int option;
	do{
		l2->printLists();
		cout<<"1-Tek basamaklari basa al"<<endl;
		cout<<"2-Sayilarin basamaklarini tersle"<<endl;
		cout<<"3-En buyuk sayiyi cikar"<<endl;
		cout<<"4-Cikar"<<endl;
		cin>>option;

		switch (option)
		{
		case 1:
			l2->moveOddDigitsToHead();
			l2->printLists();
			cout<<"Ana menuye yönledirecektir";
			break;
		case 2:
			l2->reverseNodes();
			l2->printLists();
			cout<<"Ana menuye yönledirecektir";
			break;
		case 3:
			l2->removeMax();
			l2->printLists();
			cout<<"Ana menuye yönledirecektir";
		default:
			cout<<"Cikis islemleriniz yapilacaktir";
			break;
		}
	}while(option != 4);


	



	delete l1;

	delete l2;

	return 0;
}

