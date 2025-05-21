#include "customer.h"
#include "server.h"
#include "basic.h"
using namespace std;
int main(){

    customerL *Clist=new customerL();
    customerL *Clist2=new customerL();
    server *svr = new server();

    int m=-1;
    while(m!=0){
            cout<<"-------------"<<endl;
        cout<<"CALL CENTRE"<<endl;
        cout<<"-------------"<<endl;
    cout<<endl;
    cout<<"1.Call as Customer"<<endl;
    cout<<"2.Enter as agent"<<endl;
    cout<<"3.Enter Server"<<endl;


    cout<<"press 0 to exit"<<endl<<endl;
    cout<<"Enter :";

    cin>>m;
    if(m==0){
        break;
    }

    if(m==1){
            cout<<"Please Enter your Details"<<endl;
    cout<<"\tEnter Customer id: ";
    int id;
    string name;
    cin>>id;
    cout<<"\tEnter Customer Name: ";
    cin>>name;
    if(Clist2->size()>=Clist->size())
    Clist->Cus_enQ(id,name);
    else
        Clist2->Cus_enQ(id,name);
    cout<<endl;
    cout<<"Your Call is in Queue.Please Wait...";

    }


    if(m==2){
        int a=-1;
            while(a!=0){
             cout<<"\tAGENT TARMINAL"<<endl<<endl;
            cout<<"\t1.Agent 1."<<endl;
    cout<<"\t2.Agent 2."<<endl;
    cout<<"\t0.Exit."<<endl;
     cout<<"\tEnter : ";

    cin>>a;
    if(a==0)
        break;
    else if(a==1){
        int a=-1;
            while(a!=0){
                    Clist->display();
             cout<<"\t\tCALL TARMINAL"<<endl<<endl;
            cout<<"\t\t1.Accept Call."<<endl;
    cout<<"\t\t2.Decline Call."<<endl;
    cout<<"\t\t3.Transfer Call."<<endl;
    cout<<"\t\t0.Exit."<<endl;
     cout<<"\t\tEnter : ";

    cin>>a;
    if(a==0)
        break;
    else if(a==1){
            cout<<endl;


        cout<<"\t\tAccepted the call of id:"<<Clist->topd()<<endl;
         cout<<"\t\tPress 0 to end the call"<<endl;
        cout<<"\t\tIN Call..."<<endl<<endl;
        int t;
         t=calculateExecutionTime(exampleFunction);
        svr->push(Clist->topd(),t,Clist->topa()->name,"Agent 1");
        Clist->Cus_dQ();

    }
    else if(a==2){
            svr->push(Clist->topd(),Clist->topa()->name,"Agent 1");
        Clist->Cus_dQ();
    }
    else if(a==3){
        Clist2->Cus_enQ(Clist->topa()->id,Clist->topa()->name);
        Clist->Cus_dQ();
        cout<<endl;
        cout<<"Call Transfered Successfully";
    }

    }

    }
                else if(a==2){
        int a=-1;
            while(a!=0){
                    Clist2->display();
             cout<<"\t\tCALL TARMINAL"<<endl<<endl;
            cout<<"\t\t1.Accept Call."<<endl;
    cout<<"\t\t2.Decline Call."<<endl;
    cout<<"\t\t3.Transfer Call."<<endl;
    cout<<"\t\t0.Exit."<<endl;
     cout<<"\t\tEnter : ";

    cin>>a;
    if(a==0)
        break;
    else if(a==1){
            cout<<endl;


        cout<<"\t\tAccepted the call of id:"<<Clist2->topd()<<endl;
         cout<<"\t\tPress 0 to end the call"<<endl;
        cout<<"\t\tIN Call..."<<endl<<endl;
        int t;
         t=calculateExecutionTime(exampleFunction);
        svr->push(Clist2->topd(),t,Clist2->topa()->name,"Agent 1");
        Clist2->Cus_dQ();

    }
    else if(a==2){
         svr->push(Clist2->topd(),Clist2->topa()->name,"Agent 1");
        Clist2->Cus_dQ();
    }
    else if(a==3){
        Clist->Cus_enQ(Clist2->topa()->id,Clist2->topa()->name);
        Clist2->Cus_dQ();
        cout<<endl;
        cout<<"Call Transfered Successfully";
    }

    }



    }

    }

    }

    if(m==3){
        cout<<"\t1.Enter password: ";
        string a;
        cin>>a;
        if(a=="admin"){


        int a=-1;
            while(a!=0){

             cout<<"\tSERVER TARMINAL"<<endl<<endl;
            cout<<"\t1.Check The Current Queue."<<endl;
    cout<<"\t2.Print recent Call History."<<endl;
    cout<<"\t3.Total Call Count."<<endl;
    cout<<"\t0.Exit."<<endl;
     cout<<"\tEnter : ";

    cin>>a;
    if(a==0)
        break;
    else if(a==1){
            cout<<endl;
cout<<"For 1st Line";
        Clist->display();
cout<<"For 2nd Line";
        Clist2->display();
    }
    else if(a==2){
        svr->display();
    }
    else if(a==3){
            cout<<endl;
        cout<<"TOTAL CALLS:"<<endl;
        cout<<"Total Recieved calls: "<<svr->R_call<<endl;
        cout<<"Total Declined calls: "<<svr->D_call<<endl;
    }

    }




        }
        else
            cout<<"\tInvalid Password";
    }


    if(m<0 || m>10)
        cout<<endl<<"Invalid Option"<<endl;



    cout<<endl;
    }


}
