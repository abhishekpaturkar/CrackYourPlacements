class Solution
{
public:
    /*
        Input: 1->2->3->4->5->6->7->8->NULL

        l1 = 1->2->3->4->NULL
        reverse second half
        l2 = 8->7->6->5->NULL
        merge l1 and l2

        Output: 1->8->2->7->3->6->4->5->NULL
    */

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

    void merge(ListNode *l1, ListNode *l2)
    {
        while (l1 != NULL)
        {
            ListNode *l1_next = l1->next;
            ListNode *l2_next = l2->next;

            l1->next = l2;

            if (l1_next == NULL)
            {
                break;
            }

            l2->next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
    }

    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        ListNode *l1 = head;   // Head of First
        ListNode *slow = head; // Head of Second
        ListNode *fast = head;
        ListNode *prev = head;

        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        ListNode *l2 = reverse(slow);

        merge(l1, l2);
    }
};