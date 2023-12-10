#include<iostream>
#define max 10
using namespace std;

class stk
{
    char stck[max];
    char expr[max];
    int top;

public:
    stk()
    {
        top = -1;
    }

    void getexp();
    void push(char a);
    void rev();
    void display();
    void checkpalin();
};

void stk::getexp()
{
    cout << "Enter expression: ";
    cin >> expr;
    cout<<"The expression="<<expr<<endl;
}


void stk::push(char a)
{
    if (top == max - 1)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        top++;
        stck[top] = a;
    }
}

void stk::display()
{
    int i=top;
    while(i!=-1)
    {cout<<stck[i];
    i--;}
    cout<<endl;
}

void stk::rev()
{
    for (int i = 0; expr[i]!='\0'; i++)
    {
        push(expr[i]);
    }
    
}

void stk::checkpalin()
{
    int i=top;
    int j=0;
    int ispalindrome=1;
    while(i!=-1 && j!=max-1)
    {
        if(stck[i]!=expr[j])
        {ispalindrome=-1;
            break;}
        i--;
        j++;
    }
    
    if(ispalindrome==1)
    {cout<<"The expression is palindrome"<<endl;}
    else
    {cout<<"The expression is not a palindrome"<<endl;}
}

int main()
{
    stk obj1;
    obj1.getexp();
    obj1.rev();
    obj1.display();
    obj1.checkpalin();


    return 0;
}