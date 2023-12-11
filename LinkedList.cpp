#include<iostream>
using namespace std;


class Node
{
public:
    int data;
    Node* next;
};
class LinkedList
{
public:
    Node* head;




LinkedList():head(NULL)
{
    //ctor
}


~LinkedList()
{
}


bool IsEmpty()
{
return(head == NULL);
}


void InsertFirst(int new_value)
    {
        Node* new_node = new Node();
        new_node->data = new_value;
        if(IsEmpty())
        {
            new_node->next = NULL;
            head = new_node;
            return;
        }
        new_node->next = head;
        head = new_node;

    }


void Display()
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<endl;
    }


int Count()
    {
        int counter;
        Node* temp = head;
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
        Node* temp = head;
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
        else if(IsFound(item))
        {
            Node* new_node = new Node();
            new_node->data=new_value;
            Node* temp = head;
            while(temp!=NULL && temp->next->data!=item)
            {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next=new_node;
        }
        else
            cout<<"item is not found in list\n";

    }


void Append(int new_value)
    {
        if(IsEmpty())
            InsertFirst(new_value);
        else
        {
            Node* temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            Node* new_node = new Node();
            new_node->data = new_value;
            temp->next=new_node;
            new_node->next=NULL;
        }

    }


void Delete(int key)
{
    if(IsEmpty())
        cout<<"list is empty , no items to delete\n";
    else if(IsFound(key))
    {
        if(head->data == key)
        {
            Node* del_ptr = head;
            head = head->next;
            delete del_ptr;
        }
        else
        {
            Node* prev = NULL;
            Node* del_ptr = head;
            while(del_ptr->data!=key)
            {
                prev = del_ptr;
                del_ptr = del_ptr->next;
            }
            prev->next = del_ptr->next;
            delete del_ptr;
        }
        cout<<"node deleted succesffuly...\n";
    }else
        cout<<"item you enter not found in list ...\n";

}
};