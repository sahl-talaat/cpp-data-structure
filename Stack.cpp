#include<iostream>
using namespace std;


class Node_s
{
public:
    int data;
    Node_s* next;
};
class Stack
{
public:
    Node_s* top;

Stack()
{
    top = NULL;
}


~Stack()
{


}


bool IsEmpty()
{
    return(top==NULL);
}


bool IsFull()
{
    bool full = false;
    Node_s* ptr = new Node_s();
    if(ptr == NULL)
        full = true;
    return full;
}


void Push(int item)
{

    Node_s* new_node = new Node_s();
    new_node->data = item;
    if(IsEmpty())
    {
        new_node->next = NULL;
        top = new_node;
        return;
    }
    new_node->next = top;
    top = new_node;
}


int Pop()
{
    if(IsEmpty())
        return -1;
    int value_deleted;
    Node_s* del_ptr = top;
    value_deleted = top->data;
    top = top->next;
    delete del_ptr;
    return value_deleted;
}


void Display()
{
    Node_s* temp = top;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
        cout<<endl;
}


int StackCount()
{
    int counter = 0;
    Node_s* temp = top;
    while(temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

bool IsFound(int key)
{
    bool found = false;
    Node_s* temp = top;
    while(temp != NULL)
    {
        if(temp->data==key)
            found = true;
        temp = temp->next;
    }
    return found;
}
};