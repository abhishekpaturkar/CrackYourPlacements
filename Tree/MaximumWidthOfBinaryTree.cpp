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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        long width = 0;
        queue<pair<TreeNode *, long>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            long l = q.size();
            long start = q.front().second;
            long end = q.back().second;
            width = max(width, end - start + 1);
            for (int i = 0; i < l; i++)
            {
                pair<TreeNode *, int> temp = q.front();
                q.pop();
                if (temp.first->left)
                    q.push({temp.first->left, (long)2 * temp.second + 1});
                if (temp.first->right)
                    q.push({temp.first->right, (long)2 * temp.second + 2});
            }
        }
        return width;
    }
};