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
        {
            return head;
        }

        ListNode *newHead = reverse(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    int getDecimalValue(ListNode *head)
    {
        ListNode *newHead = reverse(head);

        ListNode *temp = newHead;
        int number = 0;
        int exponent = 0;
        while (temp != NULL)
        {
            if (temp->val == 1)
            {
                number += pow(2, exponent);
            }
            temp = temp->next;
            exponent++;
        }
        return number;
    }
};