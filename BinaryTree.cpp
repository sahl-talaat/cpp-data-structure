#include <iostream>

using namespace std;

struct NodeBST
{
    /* data */
};

class Node_B // struct
{
public:
    int data;
    Node_B* left;
    Node_B* right;
    Node_B(int value)
    {
        data = value;
        left=right=NULL;
    }
};


class BinaryTree
{
public:
    Node_B* root; // pivate





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


Node_B* Insert(Node_B* r,int item)
{
    //new_node->data=value;
    if(r == NULL)
    {
        Node_B* new_node = new Node_B(item);
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


void Insert(int item)
{
    root = Insert(root,item);
}


void PreOrder(Node_B* r)//root-left-right
{
    if(r==NULL)
        return;
    cout<<r->data<<"\t";
    PreOrder(r->left);
    PreOrder(r->right);
}


void InOrder(Node_B* r)//left-root-right
{
    if(r==NULL)
        return;
    InOrder(r->left);
    cout<<r->data<<"\t";
    InOrder(r->right);
}


void PostOrder(Node_B* r)//left-right-root
{
    if(r==NULL)
        return;
    PostOrder(r->left);
    PostOrder(r->right);
    cout<<r->data<<"\t";
}


Node_B* Search(Node_B* r,int key)
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


bool Search(int key)
{
    Node_B* result = Search(root , key);
    if(result == NULL)
        return false;
    else
        return true;
}


Node_B* FindMin(Node_B* r)
{
    if(r == NULL)
        return NULL;
    else if (r->left == NULL)
        return r;
    else
        FindMin(r->left);
}


Node_B* FindMax(Node_B* r)
{
    if(r == NULL)
        return NULL;
    else if (r->right == NULL)
        return r;
    else
        return FindMax(r->right);
}


Node_B* Delete(Node_B* r, int key)
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
            Node_B* _max = FindMax(r->left);
            r->data = _max->data;
            r->left = Delete(r->left,_max->data);
        }
    }
    return r;

}


};



















