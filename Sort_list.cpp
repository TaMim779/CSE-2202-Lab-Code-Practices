#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1)
            tail->next = l1;
        if (l2)
            tail->next = l2;

        return dummy.next;
    }

    ListNode *getMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *mid = getMid(head);
        ListNode *right = mid->next;
        mid->next = NULL;

        ListNode *left = sortList(head);
        right = sortList(right);

        return merge(left, right);
    }
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    string line;
    getline(cin, line);

    stringstream ss(line);
    string temp;

    ListNode *head = NULL;
    ListNode *tail = NULL;

    while (getline(ss, temp, ','))
    {
        int num = stoi(temp);
        ListNode *node = new ListNode(num);

        if (!head)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    Solution obj;
    head = obj.sortList(head);

    cout << "[";
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << ",";
        head = head->next;
    }
    cout << "]";

    return 0;
}