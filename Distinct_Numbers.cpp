#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> distinct_numbers;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        distinct_numbers.insert(x);
    }

    cout << distinct_numbers.size() << endl;

    return 0;
}