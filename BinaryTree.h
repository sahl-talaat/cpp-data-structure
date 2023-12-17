#include <bits/stdc++.h>  //include all libraries
#include "NodeBinary.h"


namespace sahl{

class BinaryTree
{
    
public: 
    nodeBinary* root;// pivate





BinaryTree()
{
    root=NULL;
}


~BinaryTree()
{
    delete root;
    std::cout<<"\t\t\t ....Tree Deleted....\n";
}


bool IsEmpty()
{
    return(root==NULL);
}


nodeBinary* InsertCycle(nodeBinary* ptrRoor,int item)
{
    if(ptrRoor == NULL)
    {
        nodeBinary* newNode = new nodeBinary(item);
        //newNode->data = item;
        ptrRoor = newNode;
    }
    else if(item < ptrRoor->data)
    {
        ptrRoor->left = InsertCycle(ptrRoor->left,item);
    }
    else
    {
        ptrRoor->right = InsertCycle(ptrRoor->right,item);
    }
    return ptrRoor;
}

void Insert(int item)
{
    root = InsertCycle(root, item);
}



void PreOrder(nodeBinary* ptrRoor)//root-left-right
{ // 1
    if(ptrRoor==NULL) // 1
        return; // 1
    std::cout<<ptrRoor->data<<"\t";
    PreOrder(ptrRoor->left); // f()
    PreOrder(ptrRoor->right);
}


void InOrder(nodeBinary* ptrRoor)//left-root-right
{
    if(ptrRoor==NULL)
        return;
    InOrder(ptrRoor->left);
    std::cout<<ptrRoor->data<<"\t";
    InOrder(ptrRoor->right);
}


void PostOrder(nodeBinary* ptrRoor)//left-right-root
{
    if(ptrRoor==NULL)
        return;
    PostOrder(ptrRoor->left);
    PostOrder(ptrRoor->right);
    std::cout<<ptrRoor->data<<"\t";
}


nodeBinary* Search(nodeBinary* ptrRoor,int key)
{
    if(ptrRoor == NULL)
        return NULL;
    else if(ptrRoor->data == key)
        return ptrRoor;
    else if(key < ptrRoor->data)
        return  Search(ptrRoor->left , key);
    else
        return Search(ptrRoor->right , key);
}


bool Search(int key)
{
    nodeBinary* result = Search(root , key);
    if(result == NULL)
        return false;
    else
        return true;
}


nodeBinary* FindMin(nodeBinary* ptrRoor)
{
    if(ptrRoor == NULL)
        return NULL;
    else if (ptrRoor->left == NULL)
        return ptrRoor;
    else
        return FindMax(ptrRoor->left);
}


nodeBinary* FindMax(nodeBinary* ptrRoor)
{
    if(ptrRoor == NULL)
        return NULL;
    else if (ptrRoor->right == NULL)
        return ptrRoor;
    else
        return FindMax(ptrRoor->right);
}


nodeBinary* Delete(nodeBinary* ptrRoor, int key)
{
    if(ptrRoor == NULL) // empty tree
        return NULL;
    else if(key < ptrRoor->data) // item exist in left sub tree
        ptrRoor->left = Delete(ptrRoor->left,key);
    else if(key > ptrRoor->data) // item exist in right sub tree
        ptrRoor->right = Delete(ptrRoor->right,key);
    else
    {
        if(ptrRoor->left == NULL && ptrRoor->right == NULL) // leaf node
            ptrRoor = NULL;
        else if(ptrRoor->left!=NULL && ptrRoor->right==NULL) // one child in left
        {
            ptrRoor->data = ptrRoor->left->data;
            delete ptrRoor->left;
            ptrRoor->left = NULL;
        }
        else if(ptrRoor->right!=NULL && ptrRoor->left==NULL) // one child in right
        {
            ptrRoor->data = ptrRoor->right->data;
            delete ptrRoor->right;
            ptrRoor->right = NULL;
        }
        else // have two child " replace it with max left
        {
            nodeBinary* _max = FindMax(ptrRoor->left);
            ptrRoor->data = _max->data;
            ptrRoor->left = Delete(ptrRoor->left,_max->data);
        }
    }
    return ptrRoor;

}


};

}

















