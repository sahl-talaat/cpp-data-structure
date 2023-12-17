
#include <bits/stdc++.h>  //include all libraries

//namespace vector{

namespace sahl{

#ifndef VECTOR
#define VECTOR

class Vector
{
public:
    int* items;
    int VectorSize;
    int capacity;


Vector(int vectorSize)// O(n) for sace & time complexity
{
    VectorSize = vectorSize;
    capacity = 0;
    items = new int[vectorSize];
}


~Vector()
{
    delete[]items;
    std::cout<<"\t\t\t ....Vector Deleted....\n";
}


void Fill( int num_of_item , int takeValue[])
{
    if(num_of_item > VectorSize && num_of_item > VectorSize - capacity)
    {
        return;
    }
    for( int i = 0 ; i < num_of_item ; i++ )
    {
        items[i] = takeValue[i];
        capacity++;
    }
} // O(n)


void Display()
{
for(int i=0 ; i<capacity ; i++) // capacity = n
    std::cout<<items[i]<<"\t";
} // time complexity O(n) // space complexity O(1)


int GetSize()
{
    return VectorSize;
} // O(1)


int Getcapacity()
{
    return capacity;
} // O(1)


int Search(int key) // 1
{
    int index = -1; // 1
    for(int i=0 ; i<capacity ; i++)  // capacity = n
    {
        if(items[i]==key) // n
        {
            index = i; // n
            break;
        }
    }
    return index; // 1
}  // f(n)= 3n + 3 // O(n)


void Append(int new_item) //1
{
    if (capacity == VectorSize) //1
        return;
    items[capacity] = new_item;
    capacity++;
} // O(1)


void Insert(int index, int new_item)
{
    if (index < 0 && index >= VectorSize)
        return;
    for(int i=capacity ; i>index ; i--)
        items[i] = items[i-1];
    items[index] = new_item;
    capacity++;
} // O(n)


void Delete(int index)
{
    if (index < 0 && index>=VectorSize)
        return;
    for(int i=index ; i<capacity-1 ; i++)
        items[i] = items[i+1];
    capacity--;
} // O(n)


void EnLarge(int new_size)
{
    if(new_size <= VectorSize)
        return;
    VectorSize = new_size;
    int* old = items;
    items = new int[new_size];
    for(int i=0 ; i<capacity ; i++)
        items[i] = old[i];
    delete[]old;
} // O(n)


void Merge(Vector other)
{
    int new_size = other.GetSize() + VectorSize;
    VectorSize = new_size;
    int* old = items;
    items = new int[new_size];
    int i,j;
    for(i=0 ; i<capacity ;i++)
    {
        items[i] = old[i];
    }
    delete[]old;
    j = i;
    for(int i=0 ; i < other.Getcapacity() ; i++)
    {
        items[j++] = other.items[i];
        capacity++;
    }

} // O(n)
};

#endif

}
