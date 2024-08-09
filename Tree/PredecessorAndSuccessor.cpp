// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {

        pre = nullptr;
        suc = nullptr;

        Node *temp = root;
        while (temp)
        {
            if (temp->key <= key)
                temp = temp->right;
            else
            {
                suc = temp;
                temp = temp->left;
            }
        }

        Node *temp2 = root;
        while (temp2)
        {
            if (temp2->key >= key)
                temp2 = temp2->left;
            else
            {
                pre = temp2;
                temp2 = temp2->right;
            }
        }
    }
};