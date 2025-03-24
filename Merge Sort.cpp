/*
███████╗░█████╗░██╗░░░██╗░░░░░██╗██╗░░░██╗██╗░░░░░
██╔════╝██╔══██╗██║░░░██║░░░░░██║██║░░░██║██║░░░░░
█████╗░░███████║██║░░░██║░░░░░██║██║░░░██║██║░░░░░
██╔══╝░░██╔══██║██║░░░██║██╗░░██║██║░░░██║██║░░░░░
██║░░░░░██║░░██║╚██████╔╝╚█████╔╝╚██████╔╝███████╗
╚═╝░░░░░╚═╝░░╚═╝░╚═════╝░░╚════╝░░╚═════╝░╚══════╝
*/
#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int>& arr, int st, int end);
void merge(vector<int>& arr, int st, int mid, int end);

void mergeSort(vector<int>& arr, int st, int end)
{
    if(st < end)
    {
        int mid = (st + end) / 2;

        // Left partition
        mergeSort(arr, st, mid);

        // Right partition
        mergeSort(arr, mid + 1, end);

        // Merge both partitions
        merge(arr, st, mid, end);
    }
}

void merge(vector<int>& arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;

    // Merging process
    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Remaining left elements
    while(i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    // Remaining right elements
    while(j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy values from temp back to original array
    for(int idx = 0; idx < temp.size(); idx++)
    {
        arr[st + idx] = temp[idx];
    }
}

int main()
{
    int x;
    cin >> x;
    vector<int> arr(x);

    // Input values into the vector
    for(int i = 0; i < x; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, x - 1);  // Sort the vector

    // Printing sorted array
    for(int i = 0; i < x; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

