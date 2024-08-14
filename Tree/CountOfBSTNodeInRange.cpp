class Solution
{
public:
    void solve(Node *root, int l, int h, int &count)
    {
        if (!root)
            return;
        solve(root->left, l, h, count);
        if (root->data >= l && root->data <= h)
        {
            count++;
        }
        solve(root->right, l, h, count);
    }
    int getCount(Node *root, int l, int h)
    {
        int count = 0;
        solve(root, l, h, count);
        return count;
    }
};