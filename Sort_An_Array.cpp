#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int left, int mid, int right)
{
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
            temp.push_back(nums[i++]);
        else
            temp.push_back(nums[j++]);
    }

    while (i <= mid)
        temp.push_back(nums[i++]);
    while (j <= right)
        temp.push_back(nums[j++]);

    for (int k = 0; k < temp.size(); k++)
        nums[left + k] = temp[k];
}

void mergeSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cin.ignore();

    cout << "Enter elements (comma or space separated): ";
    string input;
    getline(cin, input);

    vector<int> nums;

    for (char &c : input)
    {
        if (c == ',')
            c = ' ';
    }

    stringstream ss(input);
    int x;
    while (ss >> x)
    {
        nums.push_back(x);
    }

    if (nums.size() != n)
    {
        cout << "Warning: Number of inputs doesn't match n!" << endl;
    }

    mergeSort(nums, 0, nums.size() - 1);

    cout << "Sorted array: [";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;

    return 0;
}