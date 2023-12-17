#include <bits/stdc++.h>  //include all libraries
#include "NodeAll.h"

namespace sahl{


class Queue
{
nodeAll* front;
nodeAll* rear;


public:
    
Queue()
{
    front = rear = NULL;
}


~Queue()
{
    delete front;
    delete rear;
    std::cout<<"\t\t\t ....Queue Deleted....\n";
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
    nodeAll* temp = front;
    while(temp!=NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}


void EnQueue(int item)
{
    nodeAll* new_node = new nodeAll;
    new_node->data= item;
    if(IsEmpty())
    {
        front=rear=new_node;
        return;
    }
    rear->next=new_node;
    rear = new_node;
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
    nodeAll* del_ptr = front;
    front = front->next;
    value_deleted = del_ptr->data;
    delete del_ptr;
    return value_deleted;
}


void Display()
{
    nodeAll* temp = front;
    while(temp!=NULL)
    {
        std::cout<<temp->data<<"\t";
        temp = temp->next;
    }
}


bool IsFound(int key)
{
    bool found = false;
    nodeAll* temp = front;
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
}
