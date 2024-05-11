#include<iostream>
#include<string>
using namespace std;

struct node
{
    string name;
    node *next;
    node *down;
    int flag;
};

class GLL_Book
{
    
    public:
        node *head;
        GLL_Book()
        {
            head=NULL;
        }
        node* create();
        void insertB();
        void insertC();
        void insertS();
        void insertSS();
        void display();
};

node* GLL_Book::create()
{
    node *t=new node();
    string a;
    cout<<"Enter name=";
    cin>>a;
    t->name=a;
    t->next=NULL;
    t->down=NULL;
    t->flag=0;
    return t;
}

void GLL_Book:: insertB()
{
    if(head==NULL)
    {
        node *t1=create();
        head=t1;
    }
    
    else
    {
        cout<<"Book already exists!!"<<endl;
    }
}

void GLL_Book::insertC()
{
    if(head==NULL)
    {
        cout<<"Book does not exist!!"<<endl;
        return;
    }
    
    else
    {
        int a;
        cout<<"Enter Number of chapters to be inserted=";
        cin>>a;
        for(int i=0;i<a;i++)
        {
            node *t1=create();
            
            if(head->flag==0)
            {
                head->down=t1;
                head->flag=1;
            }
            
            else
            {
                node *t2=head->down;
                while(t2->next!=NULL)
                {t2=t2->next;}
                t2->next=t1;
            }
        }
    }
}

void GLL_Book::insertS()
{
    if(head==NULL)
    {
        cout<<"Book does not exist!!"<<endl;
        return;
    }
    
    else
    {
        int a;
        string b;
        cout<<"Enter chapter under which it is to be inserted=";
        cin>>b;
        
        node *temp=head->down;
        while(temp->name!=b)
        {temp=temp->next;}
        
        if(temp==NULL)
            {cout<<"Chapter does not exists!!";
            return;
            }
        
        else
            {
            cout<<"Enter Number of Sections to be inserted=";
            cin>>a;
            for(int i=0;i<a;i++)
            {
                node *t1=create();
                
                if(temp->flag==0)
                {
                    temp->down=t1;
                    temp->flag=1;
                }
                
                else
                {
                    node *t2=temp->down;
                    while(t2->next!=NULL)
                    {t2=t2->next;}
                    t2->next=t1;
                }
            }
        }
    }
}

void GLL_Book::insertSS()
{
    if(head==NULL)
    {
        cout<<"Book does not exist!!"<<endl;
        return;
    }
    
    else
    {
        int a;
        string b,c;
        cout<<"Enter chapter under which it is to be inserted=";
        cin>>b;
        
        node *temp=head->down;
        while(temp->name!=b)
        {temp=temp->next;}
        
        if(temp==NULL)
            {cout<<"Chapter does not exists!!";
            return;
            }
        
        else
            {
                cout<<"Enter section under which it is to be inserted=";
                cin>>c;
                
                node *temp1=temp->down;
                while(temp1->name!=c)
                {temp1=temp1->next;}
                
                if(temp==NULL)
                    {cout<<"Section does not exist!!";
                        return;
                    }
                
                else{
                    cout<<"Enter Number of Sections to be inserted=";
                    cin>>a;
                    for(int i=0;i<a;i++)
                    {
                        node *t1=create();
                        
                        if(temp1->flag==0)
                        {
                            temp1->down=t1;
                            temp1->flag=1;
                        }
                        
                        else
                        {
                            node *t2=temp1->down;
                            while(t2->next!=NULL)
                            {t2=t2->next;}
                            t2->next=t1;
                        }
                    }
                }
            }
    }
}

void GLL_Book::display()
{
    if(head==NULL)
    {cout<<"Book does not exists!!"<<endl;
        return;
    }
    
    else
    {
        node *temp=head;
        cout<<"\nBOOK="<<temp->name<<endl;
        if(temp->flag==1)
        {
            temp=temp->down;
            while(temp!=NULL)
            {
                cout<<"\tCHAPTER="<<temp->name<<endl;
                node *t1=temp;
                if(t1->flag==1)
                {
                    t1=t1->down;
                    while(t1!=NULL)
                    {
                        cout<<"\t\tSECTION="<<t1->name<<endl;
                        node *t2=t1;
                        if(t2->flag==1)
                        {
                            t2=t2->down;
                            while(t2!=NULL)
                            {
                                cout<<"\t\t\tSUB-SECTION="<<t2->name<<endl;
                                t2=t2->next;
                            }
                        }
                        t1=t1->next;
                    }
                }
                temp=temp->next;
            }
        }
        
    }
}

int main()
{
    GLL_Book b1;
    b1.insertB();
    b1.insertC();
    b1.insertS();
    b1.insertS();
    b1.insertSS();
    b1.display();
    return 0;
}




