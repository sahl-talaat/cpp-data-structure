
#include<iostream>
using namespace std;
//namespace sahl
//{


class Vector
{
public:
    int* items;
    int VectorSize;
    int capacity;


Vector(int vectorSize)
{
    VectorSize = vectorSize;
    capacity = 0;
    items = new int[vectorSize];
}


~Vector()
{
    //delete[]items;
    cout<<"\t\t\t Vector Deleted\n";
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
}


void Display()
{
for(int i=0 ; i<capacity ; i++)
    cout<<items[i]<<"\t";
}


int GetSize()
{
    return VectorSize;
}


int Getcapacity()
{
    return capacity;
}


int Search(int key)
{
    int index = -1;
    for(int i=0 ; i<capacity ; i++)
    {
        if(items[i]==key)
        {
            index = i;
            break;
        }
    }
    return index;
}


void Append(int new_item)
{
    if (capacity == VectorSize)
        return;
    items[capacity] = new_item;
    capacity++;
}


void Insert(int index, int new_item)
{
    if (index < 0 && index >= VectorSize)
        return;
    for(int i=capacity ; i>index ; i--)
        items[i] = items[i-1];
    items[index] = new_item;
    capacity++;
}


void Delete(int index)
{
    if (index < 0 && index>=VectorSize)
        return;
    for(int i=index ; i<capacity-1 ; i++)
        items[i] = items[i+1];
    capacity--;
}


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
}


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

}
};
