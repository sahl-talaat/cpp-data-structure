#include<iostream>  // to define NULL

#ifndef NODEBUNARY
#define NODEBUNARY

struct nodeBinary {
    public:
        int data;
        nodeBinary* left;
        nodeBinary* right;
        nodeBinary(int value)
        {
            data = value;
            left=right=NULL;
        }
        /* nodeBinary()
        {
            data = 0;
            left=right=NULL;
        } */
};

#endif

