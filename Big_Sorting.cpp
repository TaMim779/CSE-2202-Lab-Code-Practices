#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b)
{
    if (a.length() != b.length())
        return a.length() < b.length();
    return a < b;
}

int main()
{
    int n;
    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), compare);

    for (string s : arr)
    {
        cout << s << endl;
    }

    return 0;
}