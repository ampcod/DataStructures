#include<iostream>
using namespace std;

class sll {
private:
    struct node {
        int data;
        node* next;
    }* start;

public:
    sll() {
        start = NULL;
    }

    void create();
    void display();
    void insert();
    void concat(sll obj2);
    void merge(sll obj1, sll obj2);
};

void sll::create() {
    node* temp, * curr;
    int ans;
    do {
        temp = new node;
        temp->next = NULL;
        cout << "Enter data: ";
        cin >> temp->data;

        if (start == NULL) {
            start = temp;
            curr = temp;
        }
        else {
            curr->next = temp;
            curr = curr->next;
        }

        cout << "Enter one more node: ";
        cin >> ans;

    } while (ans == 1);
}

void sll::display() {
    node* t;
    t = start;
    if (t == NULL) {
        cout << "LL is empty";
    }
    else {
        while (t != NULL) {
            cout << t->data << "->";
            t = t->next;
        }
        cout << "NULL\n";
    }
}

void sll::insert()
{
    node *t,*temp,*curr;
    t=start;
    curr=start;
    temp=new node;
    temp->next=NULL;
    cout<<"Enter data for insertion=";
    cin>>temp->data;
    
    cout<<"If u want to insert at start press 1"<<endl;
    cout<<"If u want to insert at end press 2"<<endl;
    cout<<"If u want to insert at any posi press 3"<<endl;
    int ans;
    cin>>ans;
    
    if(ans==1)
    {
        temp->next=start;
        start=temp;
    }
    
    if(ans==2)
    {
        while(t->next!=NULL)
        {t=t->next;}
        t->next=temp;
    }
    if(ans==3)
    {
        cout<<"Enter posi after which data is to be inserted=";
        int posi;
        cin>>posi;
        for(int i=1;i<posi;i++)
        {curr=curr->next;}
        temp->next=curr->next;
        curr->next=temp;
    }
}


void sll::merge(sll obj1, sll obj2) {
    node* t1, * t2, * t3;
    t3 = new node;
    start = t3;
    t1 = obj1.start;
    t2 = obj2.start;

    while (t1 != NULL && t2 != NULL) {
        if (t1->data <= t2->data) {
            t3->data = t1->data;
            t1 = t1->next;
        }
        else {
            t3->data = t2->data;
            t2 = t2->next;
        }
        if (t1 != NULL || t2 != NULL) {
            t3->next = new node;
            t3 = t3->next;
            t3->next = NULL;
        }
    }

    while (t1 != NULL) {
        t3->data = t1->data;
        t1 = t1->next;
        if (t1 != NULL) {
            t3->next = new node;
            t3 = t3->next;
            t3->next = NULL;
        }
    }

    while (t2 != NULL) {
        t3->data = t2->data;
        t2 = t2->next;
        if (t2 != NULL) {
            t3->next = new node;
            t3 = t3->next;
            t3->next = NULL;
        }
    }
}

void sll::concat(sll obj2)
{
    node *t1,*t2;
    t1=start;
    t2=obj2.start;
    
    while(t1->next!=NULL)
    {t1=t1->next;}
    t1->next=t2;
}

int main() {
    sll A;
    cout << "Create list A\n";
    A.create();
    cout << "Display list A: ";
    A.display();
    A.insert();
    A.display();

    sll B;
    cout << "Create list B\n";
    B.create();
    cout << "Display list B: ";
    B.display();
    
    A.concat(B);
    A.display();
    
    sll C;
    C.merge(A, B);
    cout << "Merged list C: ";
    C.display();

   

    return 0;
}
