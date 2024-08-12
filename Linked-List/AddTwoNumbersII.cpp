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
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *newHead = reverse(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *r1 = reverse(l1);
        ListNode *r2 = reverse(l2);
        l1 = r1;
        l2 = r2;
        // sum will be sum of 2 node values and rem stores the value of tenths place integer
        int sum = 0, rem = 0;
        ListNode *res = new ListNode();

        while (l1 || l2)
        {
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            res->val = sum % 10;
            rem = sum / 10;
            ListNode *temp = new ListNode(rem);
            temp->next = res;
            res = temp;
            sum = rem;
        }
        // if rem is 0 them it should not be returned
        return rem == 0 ? res->next : res;
    }
};