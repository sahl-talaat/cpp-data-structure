#include <bits/stdc++.h>  //include all libraries
// LinkedList & Queue & Stack
namespace N
{
struct Node
{
    int data;
    Node* next;
};

struct NodeBST
{
    int data;
    NodeBST* left;
    NodeBST* right;
    NodeBST(int value)
    {
        data = value;
        left=right=std::NULL;
    }
};
}