#include<iostream>
using namespace std;

class publication
{
    string title;
    int price;
    
    public:
        publication()
        {title="";
        price=0;}
        
        publication(string t,int p)
        {title=t;
        price=p;}
    
        void getdata()
        {
        try{
            cout<<"\nEnter title=";
            cin>>title;
            cout<<"Enter price=";
            cin>>price;
            if(price<0) throw price;
         }
            catch(int p)
            {cout<<"Value cant be negative, therefor setting it to 0.\n";
            price=0;
            }
        }
        
        void putdata()
        {
            cout<<"\nPublication title="<<title<<endl;
            cout<<"Publication price="<<price<<endl;
        }
};

class book:public publication
{
    int pagecount;
    public:
        book()
        {pagecount=0;}
        
        book(string t,int p,int pgcnt):publication(t,p)
        {pagecount=pgcnt;}
        
        void getdata(void)
        {
        try{
            publication::getdata();
            cout<<"Enter pagecount=";
            cin>>pagecount;
            if(pagecount<0) throw pagecount;
        }
            catch(int pg)
            {cout<<"Value cant be negative, therefor setting it to 0\n";
            pagecount=0;
            }
        }
        
        void putdata(void)
        {
            publication::putdata();
            cout<<"The publication book has pagecount ="<<pagecount<<endl;
        }
};

class CD:public publication
{
    float time1;
    
    public:
        CD()
        {time1=0.0;}
        
        CD(string t,int p,float tim):publication(t,p)
        {time1=tim;}
        
         void getdata(void)
        {
            try{
            publication::getdata();
            cout<<"Enter time=";
            cin>>time1;
            if(time1<0) throw time1;
        }
            catch(float t)
            {cout<<"Value cant be negative, therefore setting it to 0\n";
            time1=0.0;}
            
        }
        
        void putdata(void)
        {
            publication::putdata();
            cout<<"The publication audio is of time ="<<time1<<endl;
        }
};

int main()
{
    book b;
    b.getdata();
    b.putdata();
    
    CD c;
    c.getdata();
    c.putdata();
    return 0;
}