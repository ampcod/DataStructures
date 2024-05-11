#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
}*root;

class BST
{
    public:
        BST()
        {root=NULL;}
        
        node* create(int a);
        void insert();
        void inorder(node *t);
        void display();
        int depth(node *t);
        void searchh();
};

node* BST::create(int a)
{
    node *temp=new node;
    temp->data=a;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void BST:: insert()
{
    int a;
    cout<<"Enter number=";
    cin>>a;
    node *t=create(a);
    node *t1=root;
    node *t2;
    
    if(root==NULL)
    {root=t;}
    
    else
    {
        while(t1!=NULL)
        {
            if(t->data<t1->data)
            {
                t2=t1;
                t1=t1->left;
            }
            else
            {
                t2=t1;
                t1=t1->right;
            }
            
        }
        if(t->data>t2->data)
        {t2->right=t;}
        else
        {t2->left=t;}
        
    }
    
}

void BST::inorder(node *t)
{
    if(t!=NULL)
    {
    inorder(t->left);
    cout<<t->data<<" ";
    inorder(t->right);
    }
}

void BST::display()
{
    if(root==NULL)
    {cout<<"TREE does not exists";}
    
    else
    {inorder(root);}
}

int BST:: depth(node *t)
{
    if(t!=NULL)
    {
    return (max(depth(t->left),depth(t->right))+1);}
}

void BST::searchh()
{
    int a;
    cout<<"Enter value to be searced=";
    cin>>a;
    
    node *t1=root;
    int found=0;
    
    while(t1!=NULL)
    {
        if(t1->data==a)
        {found=1;
         break;
        }
        
        else if(a>t1->data)
        {
            t1=t1->right;
        }
        else
        {
            t1=t1->left;
        }
    }
    
    if(found==1)
    {cout<<"\nValue found!!";}
    else
    {cout<<"\nNot found";}
}


int main()
{
    BST t;
    t.insert();
    t.insert();
    t.insert();
    t.insert();
    t.insert();
    t.insert();
    t.display();
    cout<<"\n"<<t.depth(root);
    t.searchh();
    return 0;
}