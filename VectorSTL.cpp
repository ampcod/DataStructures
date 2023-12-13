#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class student
{
    public:
    string name;int rollno;
    char dob[15];
    
    bool operator ==(const student &s)
    {
        return(rollno==s.rollno);
    }
    bool operator <(const student &s)
    {
        return(rollno<s.rollno);
    }
    
    friend ostream &operator <<(ostream &out,const student &s);
    friend istream &operator >>(istream &in,const student &s);
};

ostream &operator <<(ostream &out,const student &s)
{
    out<<"\n"<<s.rollno<<"\t\t"<<s.name<<"\t\t"<<s.dob;
    return out;
}
istream &operator>>(istream &in,student &s)
{
    cout<<"\nEnter rollno=";
    in>>s.rollno;
    cout<<"Enter name=";
    in>>s.name;
    cout<<"Enter date of birth=";
    in>>s.dob;
    return in;
}

bool myfunc(const student &s1,const student &s2)
{
    return(s1.rollno<s2.rollno);
}

vector<student> read()
{
    student k;
    int n;
    vector<student> j;
    cout<<"Enter number of records=";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        j.push_back(k);
    }
    return j;
}

void printfunc(const student &k)
{
    cout<<k;
}

void print(vector<student> &j)
{
    cout<<"\nROLLNO\t\tName\t\tDOB"<<endl;
    for_each(j.begin(),j.end(),printfunc);
    cout<<"\n";
}

void insert(vector<student> &j)
{
    student k;
    cin>>k;
    j.push_back(k);
}

void delet(vector<student> &j)
{
    student k;
    cout<<"Enter rollno to be deleted=";
    cin>>k.rollno;
    
    vector<student>::iterator p;
    p=find(j.begin(),j.end(),k);
    
    if(p!=j.end())
    {
        j.erase(p);
    }
    
    else
    {
        cout<<"\nNot Found";
    }
}

void search(vector<student> &j)
{
    student k;
    cout<<"Enter rollno to be searched=";
    cin>>k.rollno;
    
    vector<student>::iterator p;
    p=find(j.begin(),j.end(),k);
    
    if(p!=j.end())
    {
        cout<<*p;
    }
    else
    {
        cout<<"\nRecord no present";
    }
}

void sortRecord(vector<student> &j)
{
    sort(j.begin(),j.end(),myfunc);
}

int main()
{
    vector<student> j;
    int op;
    do{
        cout<<"\n*-----MENU-------*";
        cout<<"\n1.Create";
        cout<<"\n2.display";
        cout<<"\n3.insert";
        cout<<"\n4.Sort";
        cout<<"\n5.Delete";
        cout<<"\n6.Search";
        cout<<"\n7.Exit";
        cout<<"\n*----------------*";
        cout<<"\n";
        cout<<"\nchoice=";
        cin>>op;
        
        switch(op)
        {
            case 1:
            {
                j=read();
                break;
            }
            case 2:
            {
                print(j);
                break;
            }
            case 3:
            {
                insert(j);
                break;
            }
            case 4:
            {
                sortRecord(j);
                break;
            }
            case 5:
            {
                delet(j);
                break;
            }
            case 6:
            {
                search(j);
                break;
            }
        }
    }while(op!=7);
    return 0;
}