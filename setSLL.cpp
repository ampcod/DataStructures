#include<iostream>
using namespace std;

class sll
{
    struct node
    {
        int data;
        node *next;
    }*start;
    public:
        sll()
        {
            start=NULL;
        }
        void insert(int a);
        void display();
        void unions(sll &obj1,sll &obj2);
        void intersec(sll &obj1,sll &obj2);
        void difference(sll &obj1,sll &obj2);
};

void sll::insert(int a)
{
    node *temp,*curr;
    temp=new node;
    temp->data=a;
    temp->next=NULL;
    
    if(start==NULL)
    {
      start=temp;
      curr=temp;
    }
    else
    {
        curr->next=temp;
        curr=curr->next;
    }
}

void sll::display()
{
    node *t;
    t=start;
    if(start==NULL)
    {cout<<"LL is empty";}
    else
    {
        while(t!=NULL)
        {
            cout<<t->data<<"->";
            t=t->next;
        }
        cout<<"NULL"<<endl;
    }
}

void sll::unions(sll &obj1, sll &obj2)
{
    node *t1, *t2;
    t1 = obj1.start;
    t2 = obj2.start;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            insert(t1->data);
            t1 = t1->next;
        }
        else if (t1->data > t2->data)
        {
            insert(t2->data);
            t2 = t2->next;
        }
        else
        {
            insert(t1->data);
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    while (t1 != NULL)
    {
        insert(t1->data);
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        insert(t2->data);
        t2 = t2->next;
    }
}

void sll::intersec(sll &obj1,sll &obj2)
{
    node *t1,*t2;
    t1=obj1.start;
    while(t1!=NULL)
    {
         t2=obj2.start;
        while(t2!=NULL)
        {
            if (t1->data==t2->data)
            {insert(t1->data);}
            t2=t2->next;
        }t1=t1->next;
    }
}

void sll::difference(sll &obj1,sll &obj2)
{
    node *t1,*t2;
    t1=obj1.start;
    while(t1!=NULL)
    {
        t2=obj2.start;
        int found=0;
        while(t2!=NULL)
        {
        if(t1->data==t2->data)
        {found=1;
        break;}
        t2=t2->next;}
    if(found!=1)
    {insert(t1->data);}
    t1=t1->next;
}
}

int main()
{
    sll A;
    A.insert(1);
    A.insert(3);
    A.insert(5);
    A.insert(7);
    A.display();
    sll B;
    B.insert(2);
    B.insert(3);
    B.insert(5);
    B.display();
    sll C;
    C.unions(A,B);
    C.display();
    sll D;
    D.intersec(A,B);
    D.display();
    sll E;
    E.difference(C,D);
    E.display();
    return 0;
    
}