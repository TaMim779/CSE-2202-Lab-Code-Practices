#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'countingSort' function below.
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> countingSort(vector<int> arr)
{
    vector<int> freq(100, 0); // range is 0 to 99

    for (int x : arr)
    {
        freq[x]++;
    }

    return freq;
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

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}