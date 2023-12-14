
#include <bits/stdc++.h> 
using namespace std;
//#include "Node.cpp"
#include "Vector.cpp"
#include "LinkedList.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "BinaryTree.cpp"



//using namespace vetor; 




int main()
{
    bool ProgramRuning = true;
    bool VectorAlive = false;
    bool LinkedListAlive = false;
    bool StackAlive = false;
    bool QueueAlive = false;
    bool BSTalive = false;
    while(ProgramRuning)
    {
        std::cout<<" \t HELLO DATA STRUCTURE \n\n";
        std::cout<<"\t\t 1 : Vector \n";
        std::cout<<"\t\t 2 : LinkedList \n";
        std::cout<<"\t\t 3 : Stack \n";
        std::cout<<"\t\t 4 : Queue \n";
        std::cout<<"\t\t 5 : Binary Search Tree \n";
        std::cout<<"\t\t 0 : To Exit Progaram \n";

        int OutChose;
        std::cin>>OutChose;
        if(OutChose == 0)
        {
            ProgramRuning = false;
            break;
        }
        else if (OutChose == 1)
            VectorAlive = true;
        else if (OutChose == 2)
            LinkedListAlive = true;
        else if (OutChose == 3)
            StackAlive = true;
        else if (OutChose == 4)
            QueueAlive = true;
        else if(OutChose == 5)
            BSTalive = true;
        

        switch(OutChose)
        {
            case 1: // Vector
            {
                ///////////////// Vector ADT demon //////////////////
                int VectorOperation,num_of_item;
                std::cout<< "\t Create Vector \n";
                int vector_size;
                std::cout << "\t enter size of Vector \n";
                std::cin >>vector_size;
                Vector vector(vector_size);
                std::cout<<"how many items you want to fill ? \n";
                std::cin>>num_of_item;
                int takeValue[num_of_item];
                for( int i = 0 ; i < num_of_item ; i++ )
                {
                    cout<<"enter item number "<<i+1<<endl;
                    cin>>takeValue[i];
                }
                vector.Fill(num_of_item,takeValue);
                while (VectorAlive)
                {
                    std::cout<<"\t\t Operations of Vector \n";

                    std::cout<<"\t\t 1 : Get size and capacity of Vector \n";
                    std::cout<<"\t\t 2 : Display items of Vector \n";
                    std::cout<<"\t\t 3 : Search for item inside Vector \n";
                    std::cout<<"\t\t 4 : Append new item inside Vector \n";
                    std::cout<<"\t\t 5 : Insert new item inside Vector \n";
                    std::cout<<"\t\t 6 : Delete value inside Vector \n";
                    std::cout<<"\t\t 7 : Enlarge size of old Vector \n";
                    std::cout<<"\t\t 8 : Merge 2 Vector \n";

                    std::cout<<"\t\t 0 : To back main option \n";
                    std::cin>>VectorOperation;
                    
                    switch(VectorOperation)
                    {
                        case 0 :
                        {
                            VectorAlive = false;
                            break;
                        }
                        case 1 : // size & length
                        {
                            std::cout<<" Vector size   = "<<vector.GetSize()<<endl;
                            std::cout<<" Vector capacity = "<<vector.Getcapacity()<<endl;
                            break;
                        }
                        case 2: // display
                        {
                            std::cout<<"display Vector content \n";
                            vector.Display();
                            break;
                        }
                        case 3: // search
                        {
                            std::cout<< "enter the value to search for \n";
                            int key;
                            std::cin>>key;
                            int index = vector.Search(key);
                            if(index == -1)
                                std::cout<<"item not found \n";
                            else
                                std::cout<<" item found @ postion "<<index<<endl;
                            break;
                        }
                        case 4: // append
                        {
                            int new_item;
                            std::cout<<"enter new item to store in Vector \n";
                            std::cin>>new_item;
                            vector.Append(new_item);
                            break;
                        }
                        case 5: // insert
                        {
                            int index,new_item;
                            std::cout<<"enter index and value \n";
                            std::cin>>index;
                            std::cin>>new_item;
                            vector.Insert(index,new_item);
                            break;
                        }
                        case 6: // delete
                        {
                        int index;
                            std::cout<<"index to delete value inside \n";
                            std::cin>> index;
                            vector.Delete(index);
                            break;
                        }
                        case 7: // enlarge
                        {
                            int new_size;
                            std::cout<<"enter new size \n";
                            std::cin>> new_size;
                            vector.EnLarge(new_size);
                            break;
                        }
                        case 8: // merge
                        {
                            int new_arr_size;
                            std::cout<< "enter size of new Vector \n";
                            std::cin>>new_arr_size;
                            Vector other(new_arr_size);
                            std::cout<<"how many items you want to fill ? \n";
                            std::cin>>num_of_item;
                            int takeValue[num_of_item];
                            for( int i = 0 ; i < num_of_item ; i++ )
                            {
                                cout<<"enter item number "<<i+1<<endl;
                                cin>>takeValue[i];
                            }
                            other.Fill(num_of_item,takeValue);
                            vector.Merge(other);
                            break;
                        }
                        default:
                        {
                            std::cout << "\t\t ... re_Enter your choise ... \n";
                            break;
                        }
                    }
                }
                break;
            }
            case 2: // LINKEDLIST
            {
                
                ///////////////// Linked List ADT demon //////////////////
                LinkedList List;
                int LinkedListOperation;
                std::cout << "\t Hello this is linkedlist ADT demon!" << endl;
                std::cout<< "\t Create Linked List \n";
                int num_node;
                std::cout << "\t enter number of Node \n";
                std::cin >>num_node;
                for(int i = 0; i<num_node ; i++)
                {
                    int new_value;
                    std::cout<<"enter new item to insert_first into list \n";
                    std::cin>>new_value;
                    List.InsertFirst(new_value);
                }

                while (LinkedListAlive)
                {
                    std::cout<<"\n\t\t Operations of Linked List \n";
                    std::cout<<"\t\t 1 : Get number of node of linkedkist \n";
                    std::cout<<"\t\t 2 : Display data of linkedkist \n";
                    std::cout<<"\t\t 3 : Search for node inside linkedkist \n";
                    std::cout<<"\t\t 4 : Insert new node First of linkedlist \n";
                    std::cout<<"\t\t 5 : Insert new node Before any node inside linkedkist \n";
                    std::cout<<"\t\t 6 : Delete value inside linkedkist \n";

                    std::cout<<"\t\t 0 : To back main option \n";
                    std::cin>>LinkedListOperation;
                    
                    switch(LinkedListOperation)
                    {
                    case 0 :
                        {
                            LinkedListAlive = false;
                            break;
                        }
                    case 1 : // get count
                        {
                            std::cout<<"number of node = "<<List.Count()<<endl;
                            break;
                        }
                    case 2: // display
                        {
                            List.Display();
                            break;
                        }
                    case 3: // search
                        {
                            int key;
                            std::cout<<"enter the value you want search for\n";
                            std::cin>>key;
                            if(List.IsFound(key))
                                std::cout<<"item founded...it's already exist the list\n";
                            else
                                std::cout<<"item not found\n";
                            break;
                        }
                    case 4: // insert first
                        {
                            int new_value;
                            std::cout<<"enter new value to insert first\n";
                            std::cin>>new_value;
                            List.InsertFirst(new_value);
                            break;
                        }
                    case 5: // insert before
                        {
                            int new_value,item;
                            std::cout<<"enter new value to insert before item\n";
                            std::cin>>new_value;
                            std::cout<<"enter the item\n";
                            std::cin>>item;
                            List.InsertBefore(item,new_value);
                            break;
                        }
                    case 6: // delete item
                        {
                            int value;
                            std::cout<<"enter item to delete\n";
                            std::cin>>value;
                            List.Delete(value);
                            break;
                        }
                    default:
                        {
                            std::cout << "\t\t ... re_Enter your choise ... \n";
                            break;
                        }
                    }
                }
                break;    
            }
            case 3: // STACK
            {
                 ///////////////// Stack ADT demon //////////////////
                Stack Stck;
                int StackOperation;
                std::cout << "\t Hello this is stack ADT demon!" << endl;
                std::cout<< "\t Create Stack \n";
                int num_node;
                std::cout << "\t enter number of node to enterd\n";
                std::cin >>num_node;
                for(int i = 0; i<num_node ; i++)
                {
                    int new_value;
                    std::cout<<"enter item number "<<i+1<<" to push in stack \n";
                    std::cin>>new_value;
                    Stck.Push(new_value);
                }
                while (StackAlive)
                {
                    std::cout<<"\n\t\t Operations of Stack \n";
                    std::cout<<"\t\t 1 : Get number of item in stack \n";
                    std::cout<<"\t\t 2 : Display data of stack \n";
                    std::cout<<"\t\t 3 : Search for item inside stack \n";
                    std::cout<<"\t\t 4 : Push item to stack \n";
                    std::cout<<"\t\t 5 : Pop item from stack \n";
                    std::cout<<"\t\t 0 : To back main obtion \n";
                    std::cin>>StackOperation;

                switch(StackOperation)
                {
                    case 0:
                    {
                        StackAlive = false;
                        break;
                    }
                case 1:
                    {
                        if(Stck.IsEmpty())
                            std::cout<<"stack is empty\n";
                        else
                            std::cout<<"stack have "<<Stck.StackCount()<<" items\n";
                        break;
                    }
                case 2:
                    {
                        if(Stck.IsEmpty())
                        {
                            std::cout<<"stack is empty\n";
                            break;
                        }
                        Stck.Display();
                        break;
                    }
                case 3:
                    {
                        if(Stck.IsEmpty())
                            std::cout<<"stack is empty\n";
                        else
                        {
                            int key;
                            std::cout<<"Enter value to search for\n";
                            std::cin>>key;
                            if(Stck.IsFound(key))
                                std::cout<<key<<" is already exist the stack\n";
                            else
                                std::cout<<key<<" isn't exist the stack\n";
                        }
                        break;

                    }
                case 4:
                    {
                        int new_value;
                        std::cout<<"enter item to push it in stack \n";
                        std::cin>>new_value;
                        Stck.Push(new_value);
                        break;

                    }
                case 5:
                    {
                        if(Stck.IsEmpty())
                        {
                            std::cout<<"\t stack is empty\n";
                        }else 
                            std::cout<<"top in stack = "<<Stck.Pop()<<" : is deleted successfully \n";
                        break;

                    }
                default:
                    {
                        std::cout << "\t\t ... re_Enter your choise ... \n";
                        break;
                    }

                }
                }
                break;
            }
            case 4: // QUEUE
            {
                 ///////////////// QUEUE ADT demon //////////////////
                Queue Que;
                int QueueOperation;
                std::cout << "\t Hello this is Queue ADT demon!" << endl;
                std::cout<< "\t Create Queue \n";
                int numOfItem;
                std::cout << "\t enter number of node to enterd\n";
                std::cin >>numOfItem;
                for(int i = 0; i<numOfItem ; i++)
                {
                    int new_value;
                    std::cout<<"enter item number "<<i+1<<" to EN_Queue \n";
                    std::cin>>new_value;
                    Que.EnQueue(new_value);
                }
                
                while (QueueAlive)
                {
                    std::cout<<"\n\t\t Operations of Queue \n";
                    std::cout<<"\t\t 1 : Get number of item in queue \n";
                    std::cout<<"\t\t 2 : Display data of queue \n";
                    std::cout<<"\t\t 3 : Search for item inside queue \n";
                    std::cout<<"\t\t 4 : Enqueue ' add from rear ' \n";
                    std::cout<<"\t\t 5 : Dequeue ' delete from front '\n";
                    std::cout<<"\t\t 6 : clear all items in queue '\n";
                    std::cout<<"\t\t 0 : To back main option \n";
                    std::cin>>QueueOperation;

                switch(QueueOperation)
                {
                case 0:
                    {
                        QueueAlive = false;
                        break;
                    }
                case 1:
                    {
                        if(Que.IsEmpty())
                            std::cout<<"queue is empty\n";
                        else
                            std::cout<<"queue have "<<Que.Count()<<" items\n";
                        break;
                    }
                case 2: // display
                    {
                        if(Que.IsEmpty())
                            std::cout<<"queue is empty...\n";
                        else
                            Que.Display();
                        break;
                    }
                case 3:
                    {
                        if(Que.IsEmpty())
                            std::cout<<"queue is empty\n";
                        else
                        {
                            int key;
                            std::cout<<"Enter value to search for\n";
                            std::cin>>key;
                            if(Que.IsFound(key))
                                std::cout<<key<<" is already exist the queue\n";
                            else
                                std::cout<<key<<" isn't exist the queue\n";
                        }
                        break;
                    }
                case 4: // en-queue
                    {
                        int new_value;
                        std::cout<<"enter value to en-queue\n";
                        std::cin>>new_value;
                        Que.EnQueue(new_value);
                        break;
                    }
                case 5: // dequeue
                    {
                        if(Que.IsEmpty())
                            std::cout<<"\t Queue is empty\n";
                        else
                        {
                            std::cout << "item in front = "<<Que.GetFront()<< " is deleted successfully\n";
                            Que.DeQueue();
                        }
                        break;
                    }
                case 6: // clear
                    {
                        Que.Clear();
                        std::cout<<"queue is empty now, all item deleted successfully...\n";
                        break;
                    }
                default:
                    {
                        std::cout << "\t\t ... re_Enter your choise ... \n";
                        break;
                    }

                }
                }
                break;
            }
            case 5: // BINARY TREE
            {
                 ///////////////// BINARY SEARCH TREE  //////////////////
                BinaryTree BST;
                int BSTOperation;
                std::cout << "\t Hello this is Binary Tree!" << endl;
                std::cout<< "\t Create Tree \n";
                int numOfItem;
                std::cout << "\t enter number of node to enterd\n";
                std::cin >>numOfItem;
                for(int i = 0; i<numOfItem ; i++)
                {
                    int new_value;
                    std::cout<<"enter item number "<<i+1<<" to insert \n";
                    std::cin>>new_value;
                    BST.Insert(new_value);
                }
                
                while (BSTalive)
                {
                    std::cout<<"\n\t\t Operations of Tree \n";
                    std::cout<<"\t\t 1 : Get number of item in tree \n";
                    std::cout<<"\t\t 2 : Display data ' pre - order ' \n";
                    std::cout<<"\t\t 3 : Display data ' post - order ' \n";
                    std::cout<<"\t\t 4 : Display data ' in - order ' \n";
                    std::cout<<"\t\t 5 : Display data with 3 operation above '\n";
                    std::cout<<"\t\t 6 : Insert item to tree ' \n";
                    std::cout<<"\t\t 7 : Search for item inside tree \n";
                    std::cout<<"\t\t 8 : Find min value in tree '\n";
                    std::cout<<"\t\t 9 : Find max value in tree '\n";
                    std::cout<<"\t\t 10: Delete value from tree '\n";
                    std::cout<<"\t\t 0 : To back main option \n";
                    std::cin>>BSTOperation;
                    
                    switch(BSTOperation)
                    {
                    case 0:
                    {
                        BSTalive = false;
                        break;
                    }
                    case 1: // get count
                    {
                        /*if(q._is_empty())
                            std::cout<<"queue is empty\n";
                        else
                            std::cout<<"queue have "<<q._count()<<" items\n";*/
                        break;
                    }
                    case 2: // display  pre - order
                    {
                        if(BST.IsEmpty())
                            std::cout<<"tree is empty\n";
                        else
                        {
                            std::cout<<"Display tree content pre-order\n";
                            BST.PreOrder(BST.root);
                        }
                        std::cout<<endl;
                        break;
                    }
                    case 3: // display  post - order
                    {
                        if(BST.IsEmpty())
                            std::cout<<"tree is empty\n";
                        else
                        {
                            std::cout<<"Display tree content post-order\n";
                            BST.PostOrder(BST.root);
                        }
                        std::cout<<endl;
                        break;
                    }
                    case 4: // display  in - order
                    {
                        if(BST.IsEmpty())
                            std::cout<<"tree is empty\n";
                        else
                        {
                            std::cout<<"Display tree content in-order\n";
                            BST.InOrder(BST.root);
                        }
                        std::cout<<endl;
                        break;
                    }
                    case 5: // display 3 operation
                    {
                        if(BST.IsEmpty())
                            std::cout<<"tree is empty\n";
                        else
                        {
                            std::cout<<"Display tree content\n";
                            std::cout<<"......................................................\n";
                            BST.PreOrder(BST.root);std::cout<<endl;
                            std::cout<<"......................................................\n";
                            BST.PostOrder(BST.root);;std::cout<<endl;
                            std::cout<<"......................................................\n";
                            BST.InOrder(BST.root);std::cout<<endl;
                            std::cout<<"......................................................\n";
                        }
                        break;
                    }
                    case 6: // insert
                    {
                        int new_value;
                        std::cout<<"  enter new value to insert\n";
                        std::cin>>new_value;
                        BST.Insert(new_value);
                        std::cout<<"  value inserted successfully\n";
                        break;
                    }
                    case 7: // search
                    {
                        int key;
                        std::cout<<"  enter value to search for\n";
                        std::cin>>key;
                        if(BST.Search(BST.root,key))
                            std::cout<<"  value is founded inside tree\n";
                        else
                            std::cout<<"  value not found....\n";
                        break;

                    }
                    case 8: // min value
                    {
                        std::cout<<"\t minimum value in tree = "<<BST.FindMin(BST.root)->data<<endl;
                        break;
                    }
                    case 9: // max value
                    {
                        std::cout<<"\t maximum value in tree = "<<BST.FindMax(BST.root)->data<<endl;
                        break;
                    }
                    case 10:
                    {
                        int key;
                        std::cout<<"  enter value to delete it\n";
                        std::cin>>key;
                        BST.Delete(BST.root,key);
                        std::cout<<"  "<<key<<"  deleted successfully\n";
                        break;
                    }
                    default:
                    {
                        std::cout << "\t\t ... re_Enter your choise ... \n";
                        break;
                    
                    }

                }
            }
            break;
            }
            default:
            {
                std::cout << "\t\t .NAH.. re_Enter your choise ..NAH. \n";
                break;
            }
            break;
        }

    }

    
    finish:
        std::cout<<"\t\t BY BY \n";


    //////////////////////////// Linked List
/*





    lst.display();
    std::cout<<"enter item to append it into list\n";
    std::cin>>item_append;
    lst._append(item_append);
    lst.display();

    if(lst._is_empty())
        std::cout<< " the list is empty \n";
    else
        std::cout<<" the list content "<<lst._count()<<"\n";
*/




    return 0;

}
