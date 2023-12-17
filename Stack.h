#include <bits/stdc++.h>  //include all libraries
#include "NodeAll.h"


namespace sahl{

class Stack
{
nodeAll* top;

public:

Stack()
{
    top = NULL;
}

~Stack()
{
    delete top;
    std::cout<<"\t\t\t ....Stack Deleted....\n";
}

bool IsEmpty()
{
    return(top==NULL);
}

bool IsFull()
{
    bool full = false;
    nodeAll* ptr = new nodeAll();
    if(ptr == NULL)
        full = true;
    return full;
}  // O(1)


void Push(int item)
{

    nodeAll* newNode = new nodeAll();
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
    nodeAll* del_ptr = top;
    value_deleted = top->data;
    top = top->next;
    delete del_ptr;
    return value_deleted;
} // O(1)


void Display()
{
    nodeAll* temp = top;
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
    nodeAll* temp = top;
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
    nodeAll* temp = top;
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

}