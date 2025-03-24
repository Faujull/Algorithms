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

int main()
{
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<int> value(n), weight(n);
    vector<double> ratio(n);
    vector<int> index(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Value and Weight for item " << i + 1 << ": ";
        cin >> value[i] >> weight[i];
        ratio[i] = (double)value[i] / weight[i];
        index[i] = i;
    }

    sort(index.begin(), index.end(), [&](int a, int b)
         { return ratio[a] > ratio[b]; });

    double totalProfit = 0.0;
    int weightTaken = 0;

    for (int i = 0; i < n; i++)
    {
        int idx = index[i];
        if (weightTaken + weight[idx] <= capacity)
        {
            weightTaken += weight[idx];
            totalProfit += value[idx];
        }
        else
        {
            int remaining = capacity - weightTaken;
            totalProfit += value[idx] * ((double)remaining / weight[idx]);
            break;
        }
    }

    cout << "Maximum profit: " << totalProfit << endl;

    return 0;
}

