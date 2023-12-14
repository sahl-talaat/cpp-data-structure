



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
    /* Node_B()
    {
        data = 0;
        left=right=NULL;
    } */
};


class BinaryTree
{private:
    
public: 
    Node_B* root;// pivate





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


Node_B* InsertCycle(Node_B* ptrRoor,int item)
{
    if(ptrRoor == NULL)
    {
        Node_B* newNode = new Node_B(item);
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



void PreOrder(Node_B* ptrRoor)//root-left-right
{ // 1
    if(ptrRoor==NULL) // 1
        return; // 1
    cout<<ptrRoor->data<<"\t";
    PreOrder(ptrRoor->left); // f()
    PreOrder(ptrRoor->right);
}


void InOrder(Node_B* ptrRoor)//left-root-right
{
    if(ptrRoor==NULL)
        return;
    InOrder(ptrRoor->left);
    cout<<ptrRoor->data<<"\t";
    InOrder(ptrRoor->right);
}


void PostOrder(Node_B* ptrRoor)//left-right-root
{
    if(ptrRoor==NULL)
        return;
    PostOrder(ptrRoor->left);
    PostOrder(ptrRoor->right);
    cout<<ptrRoor->data<<"\t";
}


Node_B* Search(Node_B* ptrRoor,int key)
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
    Node_B* result = Search(root , key);
    if(result == NULL)
        return false;
    else
        return true;
}


Node_B* FindMin(Node_B* ptrRoor)
{
    if(ptrRoor == NULL)
        return NULL;
    else if (ptrRoor->left == NULL)
        return ptrRoor;
    else
        return FindMax(ptrRoor->left);
}


Node_B* FindMax(Node_B* ptrRoor)
{
    if(ptrRoor == NULL)
        return NULL;
    else if (ptrRoor->right == NULL)
        return ptrRoor;
    else
        return FindMax(ptrRoor->right);
}


Node_B* Delete(Node_B* ptrRoor, int key)
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
            Node_B* _max = FindMax(ptrRoor->left);
            ptrRoor->data = _max->data;
            ptrRoor->left = Delete(ptrRoor->left,_max->data);
        }
    }
    return ptrRoor;

}


};



















