#include <bits/stdc++.h>  //include all libraries
#include "Node.cpp"
using namespace N;




class Queue
{
private:
    N::Node* front;
    N::Node* rear;
public:
    
Queue()
{
    front = rear = NULL;
}


~Queue()
{
}


bool IsEmpty()
{
    return(front==NULL);
}


int GetFront()
{
    return front->data;
}


int GetRear()
{
    return rear->data;
}


int Count()
{
    int counter = 0;
    N::Node* temp = front;
    while(temp!=NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}


void EnQueue(int item)
{
    N::Node* newNode = new N::Node;
    newNode->data= item;
    if(IsEmpty())
    {
        front=rear=newNode;
        return;
    }
    rear->next=newNode;
    rear = newNode;
}


int DeQueue()
{
    int value_deleted = -1;
    if(front==rear)
    {
        delete front;
        front=rear=NULL;
        return front->data;
    }
    N::Node* del_ptr = front;
    front = front->next;
    value_deleted = del_ptr->data;
    delete del_ptr;
    return value_deleted;
}


void Display()
{
    N::Node* temp = front;
    while(temp!=NULL)
    {
        std::cout<<temp->data<<"\t";
        temp = temp->next;
    }
}


bool IsFound(int key)
{
    bool found = false;
    N::Node* temp = front;
    while(temp!=NULL)
    {
        if(temp->data==key)
            found = true;
        temp = temp->next;
    }
    return found;
}


void Clear()
{
    while(!IsEmpty())
    {
        DeQueue();
    }
}

};
















