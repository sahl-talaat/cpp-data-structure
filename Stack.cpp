#include <bits/stdc++.h>  //include all libraries
//#include "NodeS.cpp"

class NodeS
{
    public:
    int data;
    NodeS* next;
};



class Stack
{
private:
    NodeS* top;
public:

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
    NodeS* ptr = new NodeS();
    if(ptr == NULL)
        full = true;
    return full;
}  // O(1)


void Push(int item)
{

    NodeS* newNode = new NodeS();
    newNode->data = item;
    if(IsEmpty())
    {
        newNode->next = NULL;
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
} // O(1)


int Pop()
{
    int value_deleted = 0;
    NodeS* del_ptr = top;
    value_deleted = top->data;
    top = top->next;
    delete del_ptr;
    return value_deleted;
} // O(1)


void Display()
{
    NodeS* temp = top;
    while(temp!=NULL)
    {
        std::cout<<temp->data<<"\t";
        temp = temp->next;
    }
    std::cout<<std::endl;
    delete temp;
} // O(n)


int StackCount()
{
    int counter = 0;
    NodeS* temp = top;
    while(temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    delete temp;
    return counter;
} // O(n)

bool IsFound(int key)
{
    bool found = false;
    NodeS* temp = top;
    while(temp != NULL)
    {
        if(temp->data==key)
            found = true;
        temp = temp->next;
    }
    delete temp;
    return found;
} // O(n)
};