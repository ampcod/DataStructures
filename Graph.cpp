#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node *next;
} *head[10];

class graph
{
private:
    int v, e;

public:
    graph()
    {
        for (int i = 0; i < 10; i++)
        {
            head[i] = NULL;
        }
    }

    node *create(int num);
    void AdjList();
    void bfs(int start);
    void display();
};

node *graph::create(int num)
{
    node *temp = new node;
    temp->data = num;
    temp->next = NULL;
    return temp;
}

void graph::AdjList()
{
    int a, b;
    cout << "Enter Number of Vertices=";
    cin >> v;
    cout << "Enter number of edges=";
    cin >> e;

    for (int i = 0; i < e; i++)
    {
        cout << "Enter the vertices which form a edge=";
        cin >> a >> b;

        if (head[a] == NULL)
        {
            head[a] = create(b);
        }
        else
        {
            node *t = head[a];
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = create(b);
        }

        if (head[b] == NULL)
        {
            head[b] = create(a);
        }
        else
        {
            node *t1 = head[b];
            while (t1->next != NULL)
            {
                t1 = t1->next;
            }
            t1->next = create(a);
        }
    }
}
void graph::bfs(int start)
{
    queue<int> q;
    int visited[v];
    for(int i=0;i<v;i++)
    {visited[i]=0;}
    
    q.push(start);
    visited[start]=1;
    
    while(!q.empty())
    {
        int current=q.front();
        cout << current << " ";
        q.pop();

        node *temp = head[current];
        while (temp != NULL)
        {
            if (!visited[temp->data])
            {
                q.push(temp->data);
                visited[temp->data] = true;
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

void graph::display()
{
    node *t;
    for (int i = 0; i < v; i++)
    {
        t = head[i];
        cout << i << "->";
        while (t != NULL)
        {
            cout << t->data << "->";
            t = t->next;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    graph g;
    g.AdjList();
    g.display();
    g.bfs(0);
    return 0;
}
