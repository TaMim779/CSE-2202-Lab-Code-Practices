#include <bits/stdc++.h>
using namespace std;

long long merge_count(vector<int> &prefix, int left, int mid, int right)
{
    long long count = 0;

    for (int i = left; i <= mid; i++)
    {
        int j = mid + 1; // reset j for each i
        while (j <= right && prefix[j] <= prefix[i])
        {
            j++;
        }
        count += (right - j + 1);
    }

    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (prefix[i] <= prefix[j])
            temp.push_back(prefix[i++]);
        else
            temp.push_back(prefix[j++]);
    }

    while (i <= mid)
        temp.push_back(prefix[i++]);
    while (j <= right)
        temp.push_back(prefix[j++]);

    for (int k = left; k <= right; k++)
    {
        prefix[k] = temp[k - left];
    }

    return count;
}

long long merge_sort_count(vector<int> &prefix, int left, int right)
{
    if (left >= right)
        return 0;

    int mid = (left + right) / 2;

    long long count = 0;
    count += merge_sort_count(prefix, left, mid);
    count += merge_sort_count(prefix, mid + 1, right);
    count += merge_count(prefix, left, mid, right);

    return count;
}

int main()
{
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
            prefix[i + 1] = prefix[i] + 1;
        else
            prefix[i + 1] = prefix[i] - 1;
    }

    long long result = merge_sort_count(prefix, 0, n);

    cout << result << endl;

    return 0;
}