#include<bits/stdc++.h>
using namespace std;

class Dynamic_Array
{
public:
    int Size;
    int Capacity;
    int *arr;
    Dynamic_Array()
    {
        Size = 0;
        Capacity = 1;
        arr = new int[Capacity];
    }
    int Get(int i)
    {

        if ((i < 0 ) or (i >= Size))
        {
            cout << "Index out of Range" << endl;
            return -1;
        }
        return arr[i];

    }
    void Set(int i,int val)
    {
        if ((i < 0 ) or (i >= Size))
        {
            cout << " Index out of Range" << endl;
            return;
        }
        arr[i] = val;

    }
    void PushBack(int val)
    {
        if(Size == Capacity)
        {
            int *new_arr = new int[2*Capacity];
            for(int i=0; i<Size; i++)
            {
                new_arr[i] = arr[i];
            }
            delete(arr);
            arr = new_arr;
            Capacity *= 2;
        }
        arr[Size] = val;
        Size++;
    }
    int Get_Size()
    {
        return Size;
    }
    int Get_Capacity()
    {
        return Capacity;
    }
    void Remove(int i)
    {
        //implement the Remove Method
        if(i<0 || i>=Size)
        {
            cout<<"Index out of range"<<endl;
            return;
        }
        Size--;
        for(int j=i; j<Size; j++)
        {
            arr[j] = arr[j+1];
        }
    }


};

int main()
{
    Dynamic_Array arr;
    // for(int i =0;i<16;i++)
    // {
    //     arr.PushBack(100 + i);
    //     cout <<"Val: "<< arr.Get(i) <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<< endl;
    // }

    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    arr.PushBack(4);
    arr.PushBack(5);

    arr.Remove(2);

    for(int i=0; i<arr.Get_Size(); i++)
        cout<<arr.Get(i)<<" ";

}