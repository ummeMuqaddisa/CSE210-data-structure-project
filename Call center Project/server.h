#include <iostream>
using namespace std;
class cus_s{
    public:
int id;
bool decline=false;
int Call_time;
cus_s *next=NULL;
string name;
string agent;
cus_s(){
}
cus_s (int i,string s){
id=i;
name=s;
}

};



class server{
public:
     cus_s *top=NULL,rear,*ptr,*temp;
    int R_call=0;
    int D_call=0;
     void push(int a,int t,string s,string agnt)
    {   R_call++;
        ptr=new cus_s(a,s);
        ptr->Call_time=t;
        ptr->agent=agnt;
        if(top==NULL)
    {
        top=ptr;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
    }
    void push(int a,string s,string agnt)
    {   D_call++;
        ptr=new cus_s(a,s);
        ptr->decline=true;
        ptr->agent=agnt;
        if(top==NULL)
    {
        top=ptr;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
    }

     void pop(){
        temp=top;
        top=top->next;
        delete temp;
    }



    int size(){
    int count=0;
    temp=top;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
    }


    void display(){
    temp=top;int i=0;
    cout<<endl;
    cout<<"All Recent Customer Call List: "<<endl;
    if(top==NULL){
            cout<<endl;
        cout<<"No Customers Available."<<endl;
    }
   while(temp!=NULL){

        i++;
   if(temp->decline)
        cout<<i<<". ID: "<<temp->id<<" | Name: "<<temp->name<< " | Call was decline by "<<temp->agent;
   else
        cout<<i<<". ID: "<<temp->id<<" | Name: "<<temp->name<< " | Agent: "<<temp->agent<< " | Call Duration: "<<temp->Call_time<<"s.";
        cout<<endl;
        temp=temp->next;
    }
    cout<<endl;
    }

};
