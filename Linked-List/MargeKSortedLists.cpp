/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    { // O(m+n)
        // Base cases
        if (l1 == NULL) // or if(!l1)
            return l2;
        if (l2 == NULL) // or if(!l2)
            return l1;

        ListNode *result;
        if (l1->val <= l2->val)
        {
            result = l1;
            result->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            result = l2;
            result->next = mergeTwoLists(l1, l2->next);
        }

        return result;
    }

    ListNode *partitionAndMerge(int start, int end, vector<ListNode *> &lists)
    {
        if (start > end)
            return NULL;

        // Base case - there's only one list
        if (start == end)
        {
            return lists[start]; // or lists[end]
        }

        int mid = (start + end) / 2;

        ListNode *left = partitionAndMerge(start, mid, lists);
        ListNode *right = partitionAndMerge(mid + 1, end, lists);

        return mergeTwoLists(left, right);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        if (k == 0)
            return NULL;
        int start = 0;
        int end = k - 1;

        return partitionAndMerge(start, end, lists);
    }
};