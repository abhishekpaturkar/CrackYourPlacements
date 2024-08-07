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
    TreeNode *mergeTrees(TreeNode *r1, TreeNode *r2)
    {
        if (r1 == NULL)
            return r2;
        if (r2 == NULL)
            return r1;

        r1->val += r2->val;

        r1->left = mergeTrees(r1->left, r2->left);
        r1->right = mergeTrees(r1->right, r2->right);

        return r1;
    }
};