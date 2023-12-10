#include <iostream>
#define max 7
using namespace std;

class Cqueue
{
    int queue[max];
    int rear, front;

public:
    Cqueue()
    {
        rear = -1;
        front = -1;
    }
    void insert(int num);
    void deletee();
    void display();
};

void Cqueue::insert(int num)
{
    if ((rear == max - 1 && front == 0) || (rear + 1) % max == front)
    {
        cout << "Queue is full";
        return;
    }

    else if (front == -1)
    {
        rear = 0;
        front = 0;
    }
    else
    {
        rear = (rear + 1) % max;
    }

    queue[rear] = num;
    cout << "The order " << num << " has been placed" << endl;
}

void Cqueue::deletee()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << queue[front] << " Has been served" << endl;
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % max;
    }
}

void Cqueue::display()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    int i = front;
    cout << "Orders in queue are: ";
    do
    {
        cout << queue[i] << " ";
        i = (i + 1) % max;
    } while (i != (rear + 1) % max);
    cout << endl;
}

int main()
{
    Cqueue obj1;
    obj1.insert(1);
    obj1.insert(2);
    obj1.insert(3);
    obj1.insert(4);
    obj1.insert(5);
    obj1.insert(6);
    obj1.insert(7);
    obj1.display();
    obj1.deletee();
    obj1.deletee();
    obj1.deletee();
    obj1.insert(8);
    obj1.insert(9);
    obj1.display();
    return 0;
}
