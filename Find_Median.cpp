#include <bits/stdc++.h>
using namespace std;

void findMedian(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    cout << arr[n / 2] << endl;
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

    findMedian(arr);

    return 0;
}