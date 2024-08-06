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
    TreeNode *reverse(TreeNode *node)
    {
        if (!node)
        {
            return NULL;
        }

        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;

        reverse(node->left);
        reverse(node->right);

        return node;
    }

    TreeNode *invertTree(TreeNode *root)
    {
        reverse(root);
        return root;
    }
};