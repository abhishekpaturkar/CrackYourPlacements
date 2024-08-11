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
    unordered_map<long, int> mp;
    int count = 0;
    void dfs(TreeNode *root, int targetSum, long prefix_sum)
    {
        if (!root)
            return;
        prefix_sum += root->val;
        if (mp.find(prefix_sum - targetSum) != mp.end())
        {
            count += mp[prefix_sum - targetSum];
        }
        mp[prefix_sum]++;
        dfs(root->left, targetSum, prefix_sum);
        dfs(root->right, targetSum, prefix_sum);
        mp[prefix_sum]--;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        mp[0] = 1;
        dfs(root, targetSum, 0);
        return count;
    }
};