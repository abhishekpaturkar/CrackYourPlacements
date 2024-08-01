class Solution
{
public:
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next; // for even len we want first middle element

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *mergeList(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val >= head2->val)
            {
                temp->next = head2;
                head2 = head2->next;
            }
            else
            {
                temp->next = head1;
                head1 = head1->next;
            }
            temp = temp->next;
        }

        if (head1 != NULL)
        {
            temp->next = head1;
        }
        if (head2 != NULL)
        {
            temp->next = head2;
        }
        return dummy->next;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *middle = findMiddle(head);

        ListNode *left = head;
        ListNode *right = middle->next;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return mergeList(left, right);
    }
};