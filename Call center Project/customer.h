#include <iostream>
using namespace std;
class customer{
    public:
int id;
string name;
customer *next=NULL;

customer(){
}
customer (int a,string s){
id=a;
name=s;
}

};


class customerL{
public:
     customer *frnt=NULL,rear,*ptr,*temp;


     void Cus_enQ(int a,string s)
    {
        ptr=new customer(a,s);
        if(frnt==NULL)
    {
        frnt=ptr;
//        rear=ptr;
    }
    else
    {
        temp=frnt;
        while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
//            rear=ptr;
        }
    }

     void Cus_dQ(){
      temp=frnt;
        frnt=frnt->next;
        delete temp;
     }


     int size(){
    int s=0;
    temp=frnt;
    while(temp!=NULL){
        s++;
        temp=temp->next;
    }
    return s;
    }


    int topd(){

        return frnt->id;

    }
    customer* topa(){
        return frnt;
    }

    void display(){
    temp=frnt;int i=0;
     cout<<endl;
    cout<<"Customers In queue: "<<endl;
    if(frnt==NULL){
            cout<<endl;
        cout<<"No Customers Available."<<endl;
    }
   while(temp!=NULL){
        i++;
        cout<<i<<".ID "<<temp->id<<" | Name: "<<temp->name;
        cout<<endl;
        temp=temp->next;
    }
    cout<<endl;
    }
};
