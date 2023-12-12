#include <bits/stdc++.h>  //include all libraries
#include "Node.cpp"
using namespace N;





class BinaryTree
{
private:
    NodeBST* root;
    NodeBST* Insert(NodeBST* r,int item)
    {
        if(r == NULL)
        {
            NodeBST* new_node = new NodeBST(item);
            r = new_node;
        }
        else if(item < r->data)
        {
            r->left = Insert(r->left,item);
        }
        else
        {
            r->right = Insert(r->right,item);
        }
        return r;
    }
    NodeBST* Search(NodeBST* r,int key)
    {
        if(r == NULL)
            return NULL;
        else if(r->data == key)
            return r;
        else if(key < r->data)
            return  Search(r->left , key);
        else
            return Search(r->right , key);
    }

public:

BinaryTree()
{
    root=NULL;
}


~BinaryTree()
{
    //dtor
}


bool IsEmpty()
{
    return(root==NULL);
}


void Insert(int item)
{
    root = Insert(root,item);
}

void PreOrder(NodeBST* r)//root-left-right
{
    if(r==NULL)
        return;
    cout<<r->data<<"\t";
    PreOrder(r->left);
    PreOrder(r->right);
}

void InOrder(NodeBST* r)//left-root-right
{
    if(r==NULL)
        return;
    InOrder(r->left);
    cout<<r->data<<"\t";
    InOrder(r->right);
}

void PostOrder(NodeBST* r)//left-right-root
{
    if(r==NULL)
        return;
    PostOrder(r->left);
    PostOrder(r->right);
    cout<<r->data<<"\t";
}

bool Search(int key)
{
    NodeBST* result = Search(root , key);
    if(result == NULL)
        return false;
    else
        return true;
}

NodeBST* FindMin(NodeBST* r)
{
    if(r == NULL)
        return NULL;
    else if (r->left == NULL)
        return r;
    else
        return FindMin(r->left);
}

NodeBST* FindMax(NodeBST* r)
{
    if(r == NULL)
        return NULL;
    else if (r->right == NULL)
        return r;
    else
        return FindMax(r->right);
}

NodeBST* Delete(NodeBST* r, int key)
{
    if(r == NULL) // empty tree
        return NULL;
    else if(key < r->data) // item exist in left sub tree
        r->left = Delete(r->left,key);
    else if(key > r->data) // item exist in right sub tree
        r->right = Delete(r->right,key);
    else
    {
        if(r->left == NULL && r->right == NULL) // leaf node
            r = NULL;
        else if(r->left!=NULL && r->right==NULL) // one child in left
        {
            r->data = r->left->data;
            delete r->left;
            r->left = NULL;
        }
        else if(r->right!=NULL && r->left==NULL) // one child in right
        {
            r->data = r->right->data;
            delete r->right;
            r->right = NULL;
        }
        else // have two child " replace it with max left
        {
            NodeBST* _max = FindMax(r->left);
            r->data = _max->data;
            r->left = Delete(r->left,_max->data);
        }
    }
    return r;

}


};



















