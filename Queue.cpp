#include<iostream>
using namespace std;



class Node_q // stuct , shared between queue , linkedList & stack
{
public:
    int data;
    Node_q* next;
};
class Queue
{
public:
    Node_q* _front;
    Node_q* _rear;



Queue()
{
    _front=_rear=NULL;
}


~Queue()
{
}


bool IsEmpty()
{
    return(_front==NULL);
}


int GetFront()
{
    return _front->data;
}


int GetRear()
{
    return _rear->data;
}


int Count()
{
    int counter;
    Node_q* temp = _front;
    while(temp!=NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}


void EnQueue(int item)
{
    Node_q* new_node = new Node_q;
    new_node->data= item;
    if(IsEmpty())
    {
        _front=_rear=new_node;
        return;
    }
    _rear->next=new_node;
    _rear = new_node;
}


int DeQueue()
{
    int value_deleted = -1;
    if(IsEmpty())
        cout <<"queue is empty \n";
    else if(_front==_rear)
    {
        delete _front;
        _front=_rear=NULL;
    }
    else
    {
        Node_q* del_ptr = _front;
        _front = _front->next;
        value_deleted = del_ptr->data;
        delete del_ptr;
    }
    return value_deleted;
}


void Display()
{
    Node_q* temp = _front;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
}


bool IsFound(int key)
{
    bool found = false;
    Node_q* temp = _front;
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
















