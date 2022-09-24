
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int val;
    node* next;
};

class Singly_linked_list{
public:
    node *head, *tail;
    int _size = 0;

    Singly_linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void PushBack(int n)
    {
        node* newNode = new node;
        newNode->val = n;
        newNode->next = nullptr;
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display()
    {
        node *cur = head;

        while(cur != nullptr)
        {
            cout << cur->val << endl;
            cur = cur->next;
        }
        cout<<endl;
    }

    void Reverse()
    {

        node *cur = head;
        node *prev = nullptr;
        node *next = nullptr;

        while(cur != nullptr)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;

    }



};



int main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    Singly_linked_list b;

    for(int i=n/2; i<n; i++)
    {
        b.PushBack(a[i]);
    }

    b.display();

    return 0;

}

