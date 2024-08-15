/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void solve(TreeNode *root, TreeNode *&curr)
    {
        if (root == NULL)
        {
            return;
        }

        curr = root;
        TreeNode *right = root->right;

        curr->right = root->left;
        root->left = NULL;

        solve(root->right, curr);

        curr->right = right;

        solve(right, curr);
        return;
    }
    void flatten(TreeNode *root)
    {
        solve(root, root);
    }
};