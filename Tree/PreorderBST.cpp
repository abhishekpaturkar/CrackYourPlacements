class Solution
{
public:
    // Function that constructs BST from its preorder traversal.
    Node *f(int arr[], int size, int low, int up, int &index)
    {
        if (index == size || arr[index] < low || arr[index] > up)
            return NULL;
        Node *root = newNode(arr[index++]);
        root->left = f(arr, size, low, root->data, index);
        root->right = f(arr, size, root->data, up, index);
        return root;
    }
    Node *Bst(int pre[], int size)
    {
        int index = 0;
        Node *root = f(pre, size, INT_MIN, INT_MAX, index);
        return root;
    }
};