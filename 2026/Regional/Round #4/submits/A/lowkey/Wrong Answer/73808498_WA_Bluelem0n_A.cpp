#include<iostream>

using namespace std;

bool handle(int arr[] , int size);

int main()
{
    int rounds;
    cin >> rounds;

    for(int i = 0 ; i < rounds ; i++)
    {
        int num;
        cin >> num;

        int *arr = new int[num];
        for(int j = 0 ; j < num ; j++)
        {
            cin >> arr[j];
        }

        if(handle(arr, num))
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }
}

bool handle(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] <= (i+1))
        {
            
            for(int j = i ; j < size-1 ; j++)
            {
                arr[j] = arr[j+1];
                size--;
                i--;
            }
        }
    }

    if(size == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}