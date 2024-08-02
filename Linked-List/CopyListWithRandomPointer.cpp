class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        unordered_map<Node *, Node *> oldToNew;

        Node *curr = head;
        while (curr)
        {
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while (curr)
        {
            oldToNew[curr]->next = oldToNew[curr->next];
            oldToNew[curr]->random = oldToNew[curr->random];
            curr = curr->next;
        }
        return oldToNew[head];
    }
};