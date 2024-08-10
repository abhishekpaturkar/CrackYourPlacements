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
    vector<pair<int, TreeNode *>> ancestors;
    vector<int> ans;
    bool findancestors(TreeNode *root, TreeNode *target)
    {
        if (!root)
            return false;
        if (root == target)
        {
            ancestors.push_back({-1, root});
            return true;
        }
        bool right = findancestors(root->right, target);
        bool left = findancestors(root->left, target);
        if (left)
            ancestors.push_back({1, root}); // 1 to signify left subtree
        if (right)
            ancestors.push_back({0, root}); // 0 to signify right subtree
        return right || left;
    }

    void findans(TreeNode *root, int k, int depth, int child)
    {
        if (!root)
            return;
        if (k == depth)
        {
            ans.push_back(root->val);
            return;
        }
        // if target found in left subtree, search paths in right subtree and vice-versa
        if (depth == 0 && child == 1)
        {
            findans(root->right, k, depth + 1, child);
        }
        else if (depth == 0 && child == 0)
        {
            findans(root->left, k, depth + 1, child);
        }
        else
        {
            findans(root->left, k, depth + 1, child);
            findans(root->right, k, depth + 1, child);
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        findancestors(root, target);
        for (auto [child, ptr] : ancestors)
        {
            findans(ptr, k, 0, child);
            k--;
        }
        return ans;
    }
};