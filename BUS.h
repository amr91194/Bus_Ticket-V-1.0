#ifndef BUS_H_INCLUDED
#define BUS_H_INCLUDED
#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

#include<stdio.h>
#include<fstream>
using namespace std;
class Bus
{
private:
    string bus_no;
    string arival_time;
    string departure_time;
    string source;
    string destination;


public:
     string arr[40];
     Bus *next;
    Bus()
    {
        next=NULL;
        for(int i=0;i<40;i++)
        {
            arr[i]="Empty";
        }
    }

    void setbus_no(string bn)
    {
        bus_no=bn;
    }
    void setarival_time(string ari_t)
    {
        arival_time=ari_t;
    }
    void setdeparture_time(string dep_t)
    {
        departure_time=dep_t;
    }
    void setsource(string so)
    {
        source=so;
    }
    void setdestination(string des)
    {
        destination=des;
    }
    string getbus_no()
    {
        return bus_no;
    }
    string getarival_time()
    {
       return arival_time;
    }
    string getdeparture_time()
    {
       return departure_time;
    }
    string getsource()
    {
       return source;
    }
    string getdestination()
    {
       return destination;
    }
   void print_seat()
    {
         for(int i=1;i<40;i++)
        {
            cout<<"seat"<<i<<"   "<<arr[i]<<"  ";
            if(i==3||i==6||i==9||i==12||i==15||i==18||i==21||i==24||i==27||i==30||i==33||i==36||i==39)
            {
                cout<<endl;
            }
        }
    }

};
class BusList
{

    public:
         Bus *head;
        BusList()
        {
            head=NULL;
        }

   Bus* search_by_bn(string bn)
    {
        Bus *temp=head;
        while(temp!=NULL)
        {
            if(bn==temp->getbus_no())
            {
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }


        bool insert_new_buss(string bn,string art,string dt,string sou,string des)
        {
            Bus *temp=search_by_bn(bn);
            if(temp!=NULL)
            {
                return false;
            }
            else
            {

            Bus *newbus=new Bus;
            newbus->setarival_time(art);
            newbus->setbus_no(bn);
            newbus->setsource(sou);
            newbus->setdeparture_time(dt);
            newbus->setdestination(des);
            if(head==NULL)
            {
                head=newbus;
                 return true;
            }
            else
            {
                newbus->next=head;
                head=newbus;
                 return true;
            }
            }

        }


 bool drop_buss(string bn)
    {
       Bus *temp= search_by_bn(bn);
       if(temp==NULL)
       {
           return false;
       }
       else if(temp==head)
       {
           head=temp->next;
           delete temp;
           return true;
       }
       else
       {
           Bus *temp1=head;
           Bus *temp2=head;
           while(temp1->getbus_no()!=bn)
           {
               temp2=temp1;
               temp1=temp1->next;
           }
           if(temp1->next==NULL)
           {
               temp2->next=NULL;
               delete temp1;
           }
           else
           {
           temp2->next=temp2->next->next;
           delete temp1;

           }
            return true;
       }
        }
        void printbus()
    {
        Bus *temp=head;
        if(temp==NULL)
        {
            cout<<"List was empty"<<endl;
        }
        else
        {
            while(temp!=NULL)
            {
        cout<<"*********************************************************************************"<<endl;
        cout<<"Bus no : "<<temp->getbus_no()<<"    Source : "<<temp->getsource()<<"    Destination : "<<temp->getdestination()<<"   Arrival Time :"<<temp->getarival_time()<<"  Departure Time :"<<temp->getdeparture_time()<<endl;
        cout<<"*********************************************************************************"<<endl;
        temp->print_seat();


        temp=temp->next;
        }
        }

    }
     void book_seat(string bn,int seat_no,string name)
          {
            Bus *temp= search_by_bn(bn);
            if(temp==NULL)
            {
                cout<<"Bus not found"<<endl;
                return;
            }
            else
            {
                if(temp->arr[seat_no]=="Empty")
                {
                    temp->arr[seat_no]=name;
                    cout<<"Seat reserved"<<endl;
                    cout<<"     ===================TICKET=================="<<endl;
                    cout<<"     BUS NO : "<<temp->getbus_no()<<"     "<<"SEAT NO :  "<<seat_no<<endl;
                    cout<<"     ROUTE :  "<<temp->getsource()<<"  to "<<temp->getdestination()<<endl;
                    cout<<"     NAME :"<<name<<endl;
                    cout<<"     ============================================";
                    ofstream myfile("Ticket.txt",ios::app);
                    myfile<<temp->getbus_no()<<' '<<seat_no<<' '<<temp->getsource()<<' '<<temp->getdestination()<<' '<<name<<endl;
                }
                else
                {
                    cout<<"Seat is already occupied "<<endl;
                }
            }

          }
};
class Passenger
{
private:
    string name;
    int age;
    string gender;
    string address;
    long int contact_no;
public:
    void setname(string na)
    {
        name=na;
    }
    void setage(int ag)
    {
        age=ag;
    }
    void setgender(string ge)
    {
       gender=ge;
    }
    void setaddress(string ad)
    {
        address=ad;
    }
    void setcontact_no(long int cn)
    {
        contact_no=cn;
    }
     string getname()
    {
       return name;
    }
    int getage()
    {
        return age;
    }
    string getgender()
    {
       return gender;
    }
    string getaddress()
    {
      return address;
    }
    long int getcontact_no()
    {
        return contact_no;
    }

    void printpassenger()
    {
        cout<<"NAME :"<<getname()<<endl;
        cout<<"AGE :"<<getage()<<endl;
        cout<<"GENDER :"<<getgender()<<endl;
        cout<<"ADDRESS :"<<getaddress()<<endl;
        cout<<"CONTACT_NO :"<<getcontact_no()<<endl;
    }
};



#endif // BUS_H_INCLUDED
