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
    TreeNode *helper(vector<int> &nums, int high, int low)
    {
        if (low > high)
        {
            return nullptr;
        }
        int mid = (high + low) / 2;
        TreeNode *Node = new TreeNode(nums[mid]);
        if (high == low)
        {
            return Node;
        }
        Node->left = helper(nums, mid - 1, low);
        Node->right = helper(nums, high, mid + 1);
        return Node;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = helper(nums, nums.size() - 1, 0);
        return root;
    }
};