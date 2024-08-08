/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    void solve(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&ans)
    {
        if (root == NULL)
            return;
        if (root->val < p->val && root->val < q->val)
        {
            solve(root->right, p, q, ans);
        }
        else if (root->val > p->val && root->val > q->val)
        {
            solve(root->left, p, q, ans);
        }
        else
        {
            ans = root;
            return;
        }
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans;
        solve(root, p, q, ans);
        return ans;
    }
};