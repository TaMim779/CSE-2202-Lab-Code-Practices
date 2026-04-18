#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
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

    multiset<int> s;
    s.insert(0);

    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        count += distance(s.begin(), s.lower_bound(prefix[i]));
        s.insert(prefix[i]);
    }

    cout << count << endl;

    return 0;
}