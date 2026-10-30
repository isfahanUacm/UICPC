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
            cout << "YES" << "\n";
        }

        else
        {
            cout << "NO" << "\n";
        }

        delete[] arr;
    }
}

bool handle(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] > (i+1))
        {
            return false;
        }
    }

    return true;
}