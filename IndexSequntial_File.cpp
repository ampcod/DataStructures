#include<iostream>
#include<fstream>
using namespace std;

class employee
{
    int ID;
    string name;
    string designation;
    int salary;
    
    public:
        void insert();
        void remov();
        void display();
};

void employee::insert()
{
    ofstream DataFile("employee_data.txt",ios::app);
    ofstream IndexFile("employee_index.txt",ios::app);
    
    cout<<"Enter ID=";
    cin>>ID;
    cout<<"Enter Name=";
    cin>>name;
    cout<<"Enter designation=";
    cin>>designation;
    cout<<"Enter salary=";
    cin>>salary;
    
    DataFile<<ID<<" "<<name<<" "<<designation<<" "<<salary<<endl;
    IndexFile<<ID<<" "<<DataFile.tellp()<<endl;
    
    DataFile.close();
    IndexFile.close();
}

void employee::remov()
{
    int IDindex;
    long position;
    int id;
    bool found;
    
    ifstream indexFile("employee_index.txt");
    ofstream tempIndex("tempIndex.txt");
    
    cout<<"Enter index to be deleted=";
    cin>>id;
    
    while(indexFile>>IDindex>>position)
    {
        if(IDindex==id)
        {
            found=true;
            continue;
        }
        tempIndex<<IDindex<<" "<<position<<endl;
    }
    
    indexFile.close();
    tempIndex.close();
    
    if(!found)
    {
        cout<<"Data not present in file"<<endl;
        return;
    }
    
    ifstream DataFile("employee_data.txt");
    ofstream tempData("tempData.txt");
    
    while(DataFile>>ID>>name>>designation>>salary)
    {
        if(ID==id)
        {
            continue;
        }
        
        tempData<<ID<<" "<<name<<" "<<designation<<" "<<salary<<endl;
    }
    
    DataFile.close();
    tempData.close();
    
    remove("employee_index.txt");
    rename("tempIndex.txt","employee_index.txt");
    remove("employee_data.txt");
    rename("tempData.txt","employee_data.txt");
}

void employee::display()
{
    int id,IndexID;
    long position;
    bool found;
    
    ifstream indexFile("employee_index.txt");
    ifstream DataFile("employee_data.txt");
    
    cout<<"Enter employee ID whose data is to found=";
    cin>>id;
    
    while(indexFile>>IndexID>>position)
    {
        if(IndexID==id)
        {
           found=true;
           DataFile.seekg(position);
           string line;
           getline(DataFile,line);
           cout<<line<<endl;
           break;
        }
    }
    
    if(!found)
    {
        cout<<"Data not present in file"<<endl;
    }
    
    DataFile.close();
    indexFile.close();
}

int main()
{
    employee e1;
    e1.insert();
    e1.insert();
    e1.insert();
    e1.insert();
    e1.remov();
    e1.display();
    e1.display();
    return 0;
}