/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->child != NULL)
            {
                Node *forward = temp->next;
                Node *temp_child = temp;
                temp = temp->child;
                temp_child->child = NULL;
                temp_child->next = temp;
                temp->prev = temp_child;

                while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = forward;
                if (forward != NULL)
                    forward->prev = temp;
                temp = temp_child;
            }
            temp = temp->next;
        }

        return head;
    }
};