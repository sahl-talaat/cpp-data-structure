
#include <iostream>
#include "NodeAll.h"

namespace sahl {


class LinkedList
{
private:
    nodeAll* head;
public:

    LinkedList():head(NULL)
    {
        //ctor
    }

    ~LinkedList()
    {
        delete head;
        std::cout<<"\t\t\t ....List Deleted....\n";
    }

    bool IsEmpty()
    {
        return(head == NULL);
    }

    void InsertFirst(int new_value) // 1
        {
            nodeAll* newNode = new nodeAll(); // 1
            newNode->data = new_value; // 1
            if(IsEmpty()) // 1
            {
                newNode->next = NULL; // 1
                head = newNode; // 1
                return; // 1
            }
            newNode->next = head;
            head = newNode;
        } // O(1)

    void Display()
        {
            nodeAll* temp = head;
            while(temp!=NULL)
            {
                std::cout<<temp->data<<"\t";
                temp = temp->next;
            }
            std::cout<<std::endl;
        }

    int Count()
        {
            int counter = 0;
            nodeAll* temp = head;
            while(temp!=NULL)
            {
                counter ++;
                temp = temp->next;
            }
            return counter;
        }

    bool IsFound(int key)
        {
            bool found = false;
            nodeAll* temp = head;
            while(temp != NULL)
            {
                if(temp->data == key)
                    found = true;
                temp = temp->next;
            }
            return found;
        }

    void InsertBefore(int item ,int new_value)
        {
            if(IsEmpty())
                InsertFirst(new_value);
            else if(!IsFound(item))
                return;
            nodeAll* newNode = new nodeAll();
            newNode->data=new_value;
            nodeAll* temp = head;
            while(temp!=NULL && temp->next->data!=item)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next=newNode;
        }

    void Append(int new_value)
        {
            if(IsEmpty())
            {
                InsertFirst(new_value);
                return;
            }
            nodeAll* temp = head;
            while(temp->next != NULL)
            {
                    temp = temp->next;
            }
            nodeAll* newNode = new nodeAll();
            newNode->data = new_value;
            temp->next=newNode;
            newNode->next=NULL;
        }

    void Delete(int key)
    {
        if(IsEmpty())
            return;
        else if(!IsFound(key))
            return;
        nodeAll* del_ptr = head;
        if(head->data == key)
        {
            head = head->next;
            delete del_ptr;
        }
        else
        {
            nodeAll* prev = NULL;
            while(del_ptr->data!=key)
            {
                prev = del_ptr;
                del_ptr = del_ptr->next;
            }
            prev->next = del_ptr->next;
            delete del_ptr;
        }
    }
};

}