#include <bits/stdc++.h>  //include all libraries
#include "Node.cpp"
using namespace N;




class Stack
{
private:
    N::Node* top;
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
    N::Node* ptr = new N::Node();
    if(ptr == NULL)
        full = true;
    return full;
}


void Push(int item)
{

    N::Node* newNode = new N::Node();
    newNode->data = item;
    if(IsEmpty())
    {
        newNode->next = NULL;
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}


int Pop()
{
    int value_deleted = 0;
    N::Node* del_ptr = top;
    value_deleted = top->data;
    top = top->next;
    delete del_ptr;
    return value_deleted;
}


void Display()
{
    N::Node* temp = top;
    while(temp!=NULL)
    {
        std::cout<<temp->data<<"\t";
        temp = temp->next;
    }
    std::cout<<std::endl;
    delete temp;
}


int StackCount()
{
    int counter = 0;
    N::Node* temp = top;
    while(temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    delete temp;
    return counter;
}

bool IsFound(int key)
{
    bool found = false;
    N::Node* temp = top;
    while(temp != NULL)
    {
        if(temp->data==key)
            found = true;
        temp = temp->next;
    }
    delete temp;
    return found;
}
};