#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include"hash.h"
#include<stdio.h>
#include<fstream>
#include"BUS.h"
#include"List.h"
#include"conio.h"
using namespace std;
unsigned char id= 219;
int main()
{
  /* system("color F1");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  \n\t\n\t\t\t\t ";
for (int i=0;i<23;i++)
{
    cout<<id;
    Sleep(200);
}*/
system("cls");
    BusList ob;
    int input=-1;
    int choice=-1;
     List hash[26];
    while(input!=0)
    {
        cout<<"========================================================= "<<endl;
        cout<<"===============BUS TICKET RESERVATION SYSTEM============= "<<endl;
                cout<<"========================================================= "<<endl;

       cout<<" \n1: New bus"<<endl;
       cout<<"2 : Print"<<endl;
       cout<<"3 : Drop Bus"<<endl;
       cout<<"4 : Search Bus"<<endl;
       cout<<"5 : Reserve ticket"<<endl;
       cout<<"6 : Read Bus from file"<<endl;
       cout<<"Enter 7 for ticket record details"<<endl;
       cin>>input;
       if(input==1)
       {
           string bn,ar_t,d_t,sou,des;
           cout<<"Enter BUS number"<<endl;
           fflush(stdin);
           getline(cin,bn);
            fflush(stdin);
               cout<<"Enter Source"<<endl;
           fflush(stdin);
           getline(cin,sou);
            fflush(stdin);
             cout<<"Enter Destination"<<endl;
           fflush(stdin);
           getline(cin,des);
            fflush(stdin);
              cout<<"Enter Arrival Time"<<endl;
           fflush(stdin);
           getline(cin,ar_t);
            fflush(stdin);
               cout<<"Enter Departure Time"<<endl;
           fflush(stdin);
           getline(cin,d_t);
            fflush(stdin);
            if(ob.insert_new_buss(bn,ar_t,d_t,sou,des))
            {
                cout<<"Insert successfully"<<endl;
                 ofstream file("Bus.txt",ios::app);
                  file<<bn<<' '<<ar_t<<' '<<d_t<<' '<<sou<<' '<<des<<endl;

            }
            else
            {
                cout<<"Bus is already inserted"<<endl;
            }
       }
       else if(input==6)
       {

            string bn,ar_t,d_t,sou,des;
            ifstream obj("Bus.txt");
           while(obj>>bn>>ar_t>>d_t>>sou>>des)
           {

               if(ob.insert_new_buss(bn,ar_t,d_t,sou,des))
               {
                   cout<<"Inserted"<<endl;
               }
               else
               {
                   cout<<"ERROR"<<endl;
               }
           }
       }
       else if(input==2)
       {
           ob.printbus();
       }
       else if(input==3)
       {
           string bn;
           cout<<"Enter Bus no"<<endl;
            fflush(stdin);
           getline(cin,bn);
            fflush(stdin);
           if(ob.drop_buss(bn))
           {
               cout<<"Drop successfully "<<endl;
           }
           else
           {
               cout<<"Not found"<<endl;
           }
       }
       else if(input==4)
       {
            string bn;
           cout<<"Enter Bus no"<<endl;
            fflush(stdin);
           getline(cin,bn);
            fflush(stdin);
           Bus *temp=ob.search_by_bn(bn);
           if(temp!=NULL)
           {
               cout<<"found"<<endl;
           cout<<"Bus no :"<<temp->getbus_no()<<" Route:   "<<temp->getsource()<<" to "<<temp->getdestination()<<"  Departure :  "<<temp->getdeparture_time()<<"  Arrival Time : "<<temp->getarival_time()<<endl;
           }
           else
           {
               cout<<"Bus not found"<<endl;
           }
       }
       else if(input==5)
       {

           string bn,pn;
           int se_n;
             cout<<"Enter BUS number"<<endl;
           fflush(stdin);
           getline(cin,bn);
            fflush(stdin);
              cout<<"Enter seat number"<<endl;
          cin>>se_n;
            cout<<"Enter Passenger  Name"<<endl;
           fflush(stdin);
           getline(cin,pn);
            fflush(stdin);
           ob.book_seat(bn,se_n,pn);
       }

    else if(input==7)
    {
        string na;

        do
	{
		cout.flush();
		//system("cls");
		cout.flush();
		cout<<"\t\t\n\nTotal words read are: "<<endl;
		cout<<"\n1: Read All from file: and store: ";
		cout<<"\n2: Search: ";
		cout<<"\n3: Exit: ";
		cout<<"\nEnter your choice: ";
		cin>>choice;
			ifstream fi("Ticket.txt");
		switch(choice)
		{
		case 1:
			{
			    string bn,sou,des,n;
			    int sn;

				 while(fi>>bn>>sn>>sou>>des>>n);
				{
				    cout<<n<<endl;
				    cout<<bn;
					int value=Hashing_Function(n);
					hash[value].insert_at_end(n,sou,des,bn,sn);

					cout<<"HASH VALUE:  "<<value<<endl;
				}
				break;
			}
		case 2:
			{
				cout<<"\nEnter Name: ";
				cin>>na;
				int value=Hashing_Function(na);

				cout<<"The hash value generated is: "<<value<<endl;
				if(!hash[value].isempty())
				{
					hash[value].search_list(na);
				}
				else
				{
					cout<<"Sorry , Not Found: ";
				}
				char c;
				cout<<"\n\nPress any key to continue: ";
				cout.flush();
				c=getch();
				cout.flush();

				break;

			}
		default:
			{
				break;
			}
		}
	}while(choice!=3);


    }
    }
     return 0;
    }













/*#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<windows.h>

#include "linklist.h"
#include "hashing.h"

int main()
{
	system("cls");

	int choice=0;
	int wordread=0;
	char word[45]={0};
	do
	{
		cout.flush();
		system("cls");
		cout.flush();
		cout<<"\t\t\n\nTotal words read are: "<<wordread<<endl;
		cout<<"\n1: Read All from file: and store: ";
		cout<<"\n2: Search: ";
		cout<<"\n3: Exit: ";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			{
				ifstream file("test.txt",ios::in);
				while(file.good())
				{
					cout<<"\n\t\t***************************************\n";
					cout.flush();
					file.getline(word,50);
					cout.flush();
					if(strcmp(word,"finishlist")==0)
					{
						break;
					}
					cout<<"\t\tword is: "<<word<<endl;
					int value=Hashing_Function(word);
					cout<<"\t\tHashing generated value is: "<<value<<endl ;
					wordread++;
					cout<<"\t\tInserting value into hash table: "<<endl;

					cout<<"\n\t\t***************************************\n";

					hash[value].insert_At_End(word);
				}
				cout.flush();
				file.close();
				break;
			}
		case 2:
			{
				cout<<"\nEnter word: ";
				cin>>word;
				int value=Hashing_Function(word);;

				cout<<"The hash value generated is: "<<value<<endl;
				if(!hash[value].isempty())
				{
					hash[value].search_List(word);
				}
				else
				{
					cout<<"Sorry , Not Found: ";
				}
				char c;
				cout<<"\n\nPress any key to continue: ";
				cout.flush();
				c=getch();
				cout.flush();

				break;

			}
		default:
			{
				break;
			}
		}
	}while(choice!=3);

}
*/

