class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *newHead = reverse(head->next);
        Node *front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    Node *compute(Node *head)
    {
        // your code goes here
        head = reverse(head);
        Node *curr = head;
        Node *prev = head;

        int max = head->data;

        head = head->next;
        while (head != NULL)
        {
            if (head->data >= max)
            {
                max = head->data;
                prev = head;
                head = head->next;
            }
            else
            {
                prev->next = prev->next->next;
                head = prev->next;
            }
        }
        head = reverse(curr);
        return head;
    }
};