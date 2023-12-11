#include<iostream>
using namespace std;

class complex
{
    int rl;
    int img;
    
    public:
        complex()
        {rl=0;
        img=0;}
        
        complex(int a,int b)
        {rl=a;
        img=b;}
        
        complex operator +(complex);
        complex operator *(complex);
        
        friend istream &operator >>(istream &in,complex &c)
        {
            cout<<"Enter real part=";
            in>>c.rl;
            cout<<"Enter img part=";
            in>>c.img;
            return in;
        }
        
        friend ostream &operator <<(ostream &out,complex &c)
        {
            if(c.img>=0)
            {cout<<c.rl<<"+"<<c.img<<"i"<<endl;}
            else
            {cout<<c.rl<<c.img<<"i"<<endl;}
            return out;
        }
};

complex complex::operator +(complex c)
{
    complex temp;
    temp.rl=rl+c.rl;
    temp.img=img+c.img;
    return temp;
}

complex complex::operator *(complex c)
{
    complex temp;
    temp.rl=(rl*c.rl)-(img*c.img);
    temp.img=(rl*c.img)+(img*c.rl);
    return temp;
}

int main()
{
    complex c1,c2,c3,c4;
    cout<<"default constructor="<<c1<<endl;
    
    cin>>c1;
    cin>>c2;
    c3=c1+c2;
    c4=c1*c2;
    cout<<c1<<endl;
    cout<<c2<<endl;
    cout<<c3<<endl;
    cout<<c4<<endl;
    return 0;
}