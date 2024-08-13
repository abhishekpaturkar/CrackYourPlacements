
class Solution
{
public:
    Node *merge2Lists(Node *l1, Node *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        Node *head = l1->data <= l2->data ? l1 : l2;
        head->bottom = l1->data <= l2->data ? merge2Lists(l1->bottom, l2) : merge2Lists(l1, l2->bottom);
        return head;
    }
    Node *flatten(Node *root)
    {
        if (!root or !root->next)
            return root;
        return merge2Lists(root, flatten(root->next));
    }
};