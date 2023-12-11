
#include <iostream>
using namespace std;

#include "Vector.cpp"
#include "LinkedList.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "BinaryTree.cpp"




int main()
{
    int upper_chose;
    start:
    cout<<" \t HELLO DATA STRUCTURE \n\n";
    cout<<"\t\t 1 : Array \n";
    cout<<"\t\t 2 : LinkedList \n";
    cout<<"\t\t 3 : Stack \n";
    cout<<"\t\t 4 : Queue \n";
    cout<<"\t\t 5 : Binary Search Tree \n";
    cout<<"\t\t 0 : To Exit Progaram \n";
    cin>>upper_chose;
    if(upper_chose == 0)
        goto finish;

    switch(upper_chose)
        {
            case 1: // ARRAY
            {
                ///////////////// Array ADT demon //////////////////
                int chose_array,num_of_item;
                cout << "\t Hello this is array ADT demon!" << endl;
                cout<< "\t Create Array \n";
                int vector_size;
                cout << "\t enter size of array \n";
                cin >>vector_size;
                Vector vector(vector_size);
                cout<<"how many items you want to fill ? \n";
                cin>>num_of_item;
                vector.Fill(num_of_item);
                _array:
                cout<<"\t\t Operations of Array \n";

                cout<<"\t\t 1 : Get size and length of Array \n";
                cout<<"\t\t 2 : Display items of Array \n";
                cout<<"\t\t 3 : Search for item inside Array \n";
                cout<<"\t\t 4 : Append new item inside Array \n";
                cout<<"\t\t 5 : Insert new item inside Array \n";
                cout<<"\t\t 6 : Delete value inside Array \n";
                cout<<"\t\t 7 : Enlarge size of old Array \n";
                cout<<"\t\t 8 : Merge 2 Array \n";

                cout<<"\t\t 0 : To back main option \n";
                cin>>chose_array;
                if(chose_array==0)
                    goto start;
                switch(chose_array)
                {

                    case 1 : // size & length
                    {
                        cout<<" array size = "<<vector.GetSize()<<endl;
                        cout<<" array length = "<<vector.Getcapacity()<<endl;
                        goto _array;
                    }
                    case 2: // display
                    {
                        cout<<"display array content \n";
                        vector.Display();
                        goto _array;
                    }
                    case 3: // search
                    {
                        cout<< "enter the value to search for \n";
                        int key;
                        cin>>key;
                        int index = vector.Search(key);
                        if(index == -1)
                            cout<<"item not found \n";
                        else
                            cout<<" item found @ postion "<<index<<endl;
                        goto _array;
                    }
                    case 4: // append
                    {
                        int new_item;
                        cout<<"enter new item to store in array \n";
                        cin>>new_item;
                        vector.Append(new_item);
                        goto _array;
                    }
                    case 5: // insert
                    {
                        int index,new_item;
                        cout<<"enter index and value \n";
                        cin>>index;
                        cin>>new_item;
                        vector.Insert(index,new_item);
                        goto _array;
                    }
                    case 6: // delete
                    {
                    int index;
                        cout<<"index to delete value inside \n";
                        cin>> index;
                        vector.Delete(index);
                        goto _array;
                    }
                    case 7: // enlarge
                    {
                        int new_size;
                        cout<<"enter new size \n";
                        cin>> new_size;
                        vector.EnLarge(new_size);
                        goto _array;
                    }
                    case 8: // merge
                    {
                        int new_arr_size;
                        cout<< "enter size of new array \n";
                        cin>>new_arr_size;
                        Vector other(new_arr_size);
                        cout<<"how many items you want to fill ? \n";
                        cin>>num_of_item;
                        other.Fill(num_of_item);
                        vector.Merge(other);
                        goto _array;
                    }
                    default:
                    {
                        cout << "\t\t ... re_Enter your choise ... \n";
                        goto _array;
                    }
                }
            }
            case 2: // LINKEDLIST
            {
                ///////////////// Linked List ADT demon //////////////////
                LinkedList List;
                int chose_linkedlist;
                cout << "\t Hello this is linkedlist ADT demon!" << endl;
                cout<< "\t Create Linked List \n";
                int num_node;
                cout << "\t enter number of Node \n";
                cin >>num_node;
                for(int i = 0; i<num_node ; i++)
                {
                    int new_value;
                    cout<<"enter new item to insert_first into list \n";
                    cin>>new_value;
                    List.InsertFirst(new_value);
                }
                _linkedlist:
                cout<<"\n\t\t Operations of Linked List \n";

                cout<<"\t\t 1 : Get number of node of linkedkist \n";
                cout<<"\t\t 2 : Display data of linkedkist \n";
                cout<<"\t\t 3 : Search for node inside linkedkist \n";
                cout<<"\t\t 4 : Insert new node First of linkedlist \n";
                cout<<"\t\t 5 : Insert new node Before any node inside linkedkist \n";
                cout<<"\t\t 6 : Delete value inside linkedkist \n";

                cout<<"\t\t 0 : To back main option \n";
                cin>>chose_linkedlist;
                if(chose_linkedlist==0)
                    goto start;
                switch(chose_linkedlist)
                {
                case 1 : // get count
                    {
                        cout<<"number of node = "<<List.Count()<<endl;
                        goto _linkedlist;
                    }
                case 2: // display
                    {
                        List.Display();
                        goto _linkedlist;
                    }
                case 3: // search
                    {
                        int key;
                        cout<<"enter the value you want search for\n";
                        cin>>key;
                        if(List.IsFound(key))
                            cout<<"item founded...it's already exist the list\n";
                        else
                            cout<<"item not found\n";
                        goto _linkedlist;
                    }
                case 4: // insert first
                    {
                        int new_value;
                        cout<<"enter new value to insert first\n";
                        cin>>new_value;
                        List.InsertFirst(new_value);
                        goto _linkedlist;
                    }
                case 5: // insert before
                    {
                        int new_value,item;
                        cout<<"enter new value to insert before item\n";
                        cin>>new_value;
                        cout<<"enter the item\n";
                        cin>>item;
                        List.InsertBefore(item,new_value);
                        goto _linkedlist;
                    }
                case 6: // delete item
                    {
                        int value;
                        cout<<"enter item to delete\n";
                        cin>>value;
                        List.Delete(value);
                        goto _linkedlist;
                    }
                default:
                    {
                        cout << "\t\t ... re_Enter your choise ... \n";
                        goto _linkedlist;
                    }
                }
            }
            case 3: // STACK
            {
                 ///////////////// Stack ADT demon //////////////////
                Stack Stck;
                int chose_stack;
                cout << "\t Hello this is stack ADT demon!" << endl;
                cout<< "\t Create Stack \n";
                int num_node;
                cout << "\t enter number of node to enterd\n";
                cin >>num_node;
                for(int i = 0; i<num_node ; i++)
                {
                    int new_value;
                    cout<<"enter item number "<<i+1<<" to push in stack \n";
                    cin>>new_value;
                    Stck.Push(new_value);
                }
                _stack:
                cout<<"\n\t\t Operations of Stack \n";

                cout<<"\t\t 1 : Get number of item in stack \n";
                cout<<"\t\t 2 : Display data of stack \n";
                cout<<"\t\t 3 : Search for item inside stack \n";
                cout<<"\t\t 4 : Push item to stack \n";
                cout<<"\t\t 5 : Pop item from stack \n";

                cout<<"\t\t 0 : To back main obtion \n";
                cin>>chose_stack;
                if(chose_stack==0)
                    goto start;
                switch(chose_stack)
                {
                case 1:
                    {
                        if(Stck.IsEmpty())
                            cout<<"stack is empty\n";
                        else
                            cout<<"stack have "<<Stck.StackCount()<<" items\n";
                        goto _stack;
                    }
                case 2:
                    {
                        if(Stck.IsEmpty())
                        {
                            cout<<"stack is empty\n";
                            goto _stack;
                        }
                        Stck.Display();
                        goto _stack;
                    }
                case 3:
                    {
                        if(Stck.IsEmpty())
                            cout<<"stack is empty\n";
                        else
                        {
                            int key;
                            cout<<"Enter value to search for\n";
                            cin>>key;
                            if(Stck.IsFound(key))
                                cout<<key<<" is already exist the stack\n";
                            else
                                cout<<key<<" isn't exist the stack\n";
                        }
                        goto _stack;

                    }
                case 4:
                    {
                        int new_value;
                        cout<<"enter item to push it in stack \n";
                        cin>>new_value;
                        Stck.Push(new_value);
                        goto _stack;

                    }
                case 5:
                    {
                        if(Stck.Pop() == -1)
                        {
                            cout<<"\t stack is empty\n";
                            goto _stack;
                        }
                        cout<<"top in stack = "<<Stck.Pop()<<" : is deleted successfully \n";
                        goto _stack;

                    }
                default:
                    {
                        cout << "\t\t ... re_Enter your choise ... \n";
                        goto _stack;
                    }

                }

            }
            case 4: // QUEUE
            {
                 ///////////////// QUEUE ADT demon //////////////////
                Queue Que;
                int chose_queue;
                cout << "\t Hello this is Queue ADT demon!" << endl;
                cout<< "\t Create Queue \n";
                int num_item;
                cout << "\t enter number of node to enterd\n";
                cin >>num_item;
                for(int i = 0; i<num_item ; i++)
                {
                    int new_value;
                    cout<<"enter item number "<<i+1<<" to EN_Queue \n";
                    cin>>new_value;
                    Que.EnQueue(new_value);
                }
                _queue:
                cout<<"\n\t\t Operations of Queue \n";

                cout<<"\t\t 1 : Get number of item in queue \n";
                cout<<"\t\t 2 : Display data of queue \n";
                cout<<"\t\t 3 : Search for item inside queue \n";
                cout<<"\t\t 4 : Enqueue ' add from rear ' \n";
                cout<<"\t\t 5 : Dequeue ' delete from front '\n";
                cout<<"\t\t 6 : clear all items in queue '\n";

                cout<<"\t\t 0 : To back main option \n";
                cin>>chose_queue;
                if(chose_queue==0)
                    goto start;
                switch(chose_queue)
                {
                case 1:
                    {
                        if(Que.IsEmpty())
                            cout<<"queue is empty\n";
                        else
                            cout<<"queue have "<<Que.Count()<<" items\n";
                        goto _queue;
                    }
                case 2: // display
                    {
                        if(Que.IsEmpty())
                            cout<<"queue is empty...\n";
                        else
                            Que.Display();
                        goto _queue;
                    }
                case 3:
                    {
                        if(Que.IsEmpty())
                            cout<<"queue is empty\n";
                        else
                        {
                            int key;
                            cout<<"Enter value to search for\n";
                            cin>>key;
                            if(Que.IsFound(key))
                                cout<<key<<" is already exist the queue\n";
                            else
                                cout<<key<<" isn't exist the queue\n";
                        }
                        goto _queue;
                    }
                case 4: // en-queue
                    {
                        int new_value;
                        cout<<"enter value to en-queue\n";
                        cin>>new_value;
                        Que.EnQueue(new_value);
                        goto _queue;
                    }
                case 5: // dequeue
                    {
                        if(Que.IsEmpty())
                        {
                         cout<<"\t Queue is empty\n";
                         goto _queue;
                        }
                        cout << "item in front = "<<Que.GetFront()<< " is deleted successfully\n";
                        Que.DeQueue();
                        goto _queue;
                    }
                case 6: // clear
                    {
                        Que.Clear();
                        cout<<"queue is empty now, all item deleted successfully...\n";
                        goto _queue;
                    }
                default:
                    {
                        cout << "\t\t ... re_Enter your choise ... \n";
                        goto _queue;
                    }

                }

            }
            case 5: // BINARY TREE
            {
                 ///////////////// BINARY SEARCH TREE  //////////////////
                BinaryTree BST;
                int chose_binary;
                cout << "\t Hello this is Binary Tree!" << endl;
                cout<< "\t Create Tree \n";
                int num_item;
                cout << "\t enter number of node to enterd\n";
                cin >>num_item;
                for(int i = 0; i<num_item ; i++)
                {
                    int new_value;
                    cout<<"enter item number "<<i+1<<" to insert \n";
                    cin>>new_value;
                    BST.Insert(new_value);
                }
                _binary:
                cout<<"\n\t\t Operations of Tree \n";

                cout<<"\t\t 1 : Get number of item in tree \n";
                cout<<"\t\t 2 : Display data ' pre - order ' \n";
                cout<<"\t\t 3 : Display data ' post - order ' \n";
                cout<<"\t\t 4 : Display data ' in - order ' \n";
                cout<<"\t\t 5 : Display data with 3 operation above '\n";
                cout<<"\t\t 6 : Insert item to tree ' \n";
                cout<<"\t\t 7 : Search for item inside tree \n";
                cout<<"\t\t 8 : Find min value in tree '\n";
                cout<<"\t\t 9 : Find max value in tree '\n";
                cout<<"\t\t 10: Delete value from tree '\n";

                cout<<"\t\t 0 : To back main option \n";
                cin>>chose_binary;
                if(chose_binary==0)
                    goto start;
                switch(chose_binary)
                {
                case 1: // get count
                    {
                        /*if(q._is_empty())
                            cout<<"queue is empty\n";
                        else
                            cout<<"queue have "<<q._count()<<" items\n";*/
                        goto _binary;
                    }
                case 2: // display  pre - order
                    {
                        if(BST.IsEmpty())
                            cout<<"tree is empty\n";
                        else
                        {
                            cout<<"Display tree content pre-order\n";
                            BST.PreOrder(BST.root);
                        }
                        cout<<endl;
                        goto _binary;
                    }
                case 3: // display  post - order
                    {
                        if(BST.IsEmpty())
                            cout<<"tree is empty\n";
                        else
                        {
                            cout<<"Display tree content post-order\n";
                            BST.PostOrder(BST.root);
                        }
                        cout<<endl;
                        goto _binary;
                    }
                case 4: // display  in - order
                    {
                        if(BST.IsEmpty())
                            cout<<"tree is empty\n";
                        else
                        {
                            cout<<"Display tree content in-order\n";
                            BST.InOrder(BST.root);
                        }
                        cout<<endl;
                        goto _binary;
                    }
                case 5: // display 3 operation
                    {
                        if(BST.IsEmpty())
                            cout<<"tree is empty\n";
                        else
                        {
                            cout<<"Display tree content\n";
                            cout<<"......................................................\n";
                            BST.PreOrder(BST.root);cout<<endl;
                            cout<<"......................................................\n";
                            BST.PostOrder(BST.root);;cout<<endl;
                            cout<<"......................................................\n";
                            BST.InOrder(BST.root);cout<<endl;
                            cout<<"......................................................\n";
                        }
                        goto _binary;
                    }
                case 6: // insert
                    {
                        int new_value;
                        cout<<"  enter new value to insert\n";
                        cin>>new_value;
                        BST.Insert(new_value);
                        cout<<"  value inserted successfully\n";
                        goto _binary;
                    }
                case 7: // search
                    {
                        int key;
                        cout<<"  enter value to search for\n";
                        cin>>key;
                        if(BST.Search(key))
                            cout<<"  value is founded inside tree\n";
                        else
                            cout<<"  value not found....\n";
                        goto _binary;

                    }
                case 8: // min value
                    {
                        cout<<"\t minimum value in tree = "<<BST.FindMin(BST.root)->data<<endl;
                        goto _binary;
                    }
                case 9: // max value
                    {
                        cout<<"\t maximum value in tree = "<<BST.FindMax(BST.root)->data<<endl;
                        goto _binary;
                    }
                case 10:
                    {
                        int key;
                        cout<<"  enter value to delete it\n";
                        cin>>key;
                        BST.Delete(BST.root,key);
                        cout<<"  "<<key<<"  deleted successfully\n";
                        goto _binary;
                    }
                default:
                    {
                        cout << "\t\t ... re_Enter your choise ... \n";
                        goto _binary;
                    }

                }

            }
            default:
            {
                cout << "\t\t ... re_Enter your choise ... \n";
                goto start;
            }
        }

    finish:
        cout<<"\t\t BY BY \n";


    //////////////////////////// Linked List
/*





    lst.display();
    cout<<"enter item to append it into list\n";
    cin>>item_append;
    lst._append(item_append);
    lst.display();

    if(lst._is_empty())
        cout<< " the list is empty \n";
    else
        cout<<" the list content "<<lst._count()<<"\n";
*/




    return 0;

}
