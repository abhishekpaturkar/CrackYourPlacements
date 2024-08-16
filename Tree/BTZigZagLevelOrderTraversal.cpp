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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *node;

        while (!q.empty())
        {
            vector<int> temp;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++)
            {
                node = q.front();
                temp.push_back(node->val);
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(temp);
        }

        for (int i = 0; i < ans.size(); i++)
        {
            if (i % 2 != 0)
            {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};