#include<iostream>
#include<string>
using namespace std;

enum PatientType
{
    SERIOUS,
    NOT_SERIOUS,
    GENERAL_CHECKUP
};

struct Patient
{
    string name;
    PatientType type;
};

class PQueue
{
    int front, rear, size;
    Patient p[5];

public:
    PQueue()
    {
        front = -1;
        rear = -1;
        size = 5;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return rear == (size - 1);
    }

    void enqueue();
    void dequeue();
    void display();
};

void PQueue::enqueue()
{
    if (isFull())
    {
        cout << "Queue is full!!!" << endl;
        return;
    }

    Patient patient;
    int a;
    cout << "Enter patient name=";
    cin >> patient.name;
    cout << "Enter Condition(0-SERIOUS,1-NOT_SERIOUS,2-GENERAL_CHECKUP)=";
    cin >> a;
    patient.type=static_cast<PatientType>(a);

    rear++;
    p[rear] = patient;
    if (front == -1)
    {
        front = 0;
    }

    for (int i = rear; i > front; i--) // Corrected the loop condition
    {
        if (p[i].type < p[i - 1].type)
        {
            swap(p[i], p[i - 1]);
        }
        else
        {
            break;
        }
    }
}

void PQueue::display()
{
    cout << "Discharge order:\n";
    for (int i = front; i <= rear; i++) // Added declaration for loop variable i
    {
        cout << p[i].name << endl;
    }
}

void PQueue::dequeue()
{
    if(isEmpty())
    {
        cout<<"It is empty!!"<<endl;
        return;
    }
    
    cout<<"Discharge:"<<p[front].name<<endl;
    if(front==rear)
    {front=rear=-1;}
    
    else
    {
        front++;
    }
}

int main()
{
    PQueue p;
    int ans;
    char c;
    do
    {
        cout<<"--------MENU-----------"<<endl;
        cout<<"1.Register a Patient"<<endl;
        cout<<"2.Discharge a Patient"<<endl;
        cout<<"3.Discharge order"<<endl;
        cout<<"4.exit"<<endl;
        cout<<endl;
        cout<<"Enter choice=";
        cin>>ans;
        
        switch(ans)
        {
            case 1:
                p.enqueue();
                cout<<"Patient successfully registered!!"<<endl;
                break;
            case 2:
                p.dequeue();
                cout<<"Patient Discharged successfully!!"<<endl;
                break;
            case 3:
                p.display();
                break;
                
            case 4:
                exit(0);
                
        }
        
        cout<<endl;
        cout<<"Do u wish to continue(y/n):";
        cin>>c;
        cout<<endl;
    }while(c!='n');
    return 0;
}
