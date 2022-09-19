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

void Increment_One(Dynamic_Array da)
{
    Dynamic_Array da1;
    da1.PushBack(0);

    for(int i=0; i<da.Get_Size(); i++)
    {
        da1.PushBack(da.Get(i));
    }

    int c = 0;
    if(da1.Get(da1.Get_Size()-1) == 9)
    {
        da1.Set(da1.Get_Size()-1, 0);
        c = 1;
        for(int i=da1.Get_Size()-2; i>=0; i--)
    {
        if(c == 1)
        {
            da1.Set(i, da1.Get(i)+1);
            if(da1.Get(i) == 10)
            {
                da1.Set(i, 0);
                c = 1;
            }
            else
            {
                c = 0;
            }
        }
    }
    }
    else
    {
        da1.Set(da1.Get_Size()-1, da1.Get(da1.Get_Size()-1)+1);
    }

    if(da1.Get(0) == 0)
    {
        for(int i=1; i<da1.Get_Size(); i++)
            cout<<da1.Get(i)<<" ";
    }
    else
    {
        for(int i=0; i<da1.Get_Size(); i++)
            cout<<da1.Get(i)<<" ";  
    }
}

int main()
{
    int n;
    cin>>n;

    Dynamic_Array da;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        da.PushBack(x);
    }

    Increment_One(da);
}