#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int> arr)
{
    vector<int> freq(100, 0); // values range 0–99

    // Step 1: Count frequency
    for (int x : arr)
    {
        freq[x]++;
    }

    // Step 2: Build sorted array
    vector<int> sorted;
    for (int i = 0; i < 100; i++)
    {
        while (freq[i] > 0)
        {
            sorted.push_back(i);
            freq[i]--;
        }
    }

    return sorted;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = countingSort(arr);

    // Output
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i != result.size() - 1)
            cout << " ";
    }

    return 0;
}