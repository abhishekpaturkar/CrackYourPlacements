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
    // Function to search for a number in the postorder array
    int search(vector<int> &postorder, int start, int end, int num)
    {
        for (int i = start; i <= end; i++)
        {
            if (postorder[i] == num)
            {
                return i;
            }
        }

        return -1;
    }

    // Variable to keep track of the index in the preorder array
    int preindex = 0;
    TreeNode *solve(vector<int> &preorder, vector<int> &postorder, int start, int end)
    {
        // Base case: empty subtree
        if (start > end || preindex >= preorder.size())
            return nullptr;

        // Root value for the current subtree
        int num = preorder[preindex];
        preindex++;

        TreeNode *root = new TreeNode(num);

        // Leaf node or end of current subtree
        if (preindex >= preorder.size() || start == end)
            return root;

        // The index of the next root value in the postorder array
        int postindex = search(postorder, start, end, preorder[preindex]);

        // Recursive call for left and right subtree
        root->left = solve(preorder, postorder, start, postindex);
        // end - 1 because the root node is taken out
        root->right = solve(preorder, postorder, postindex + 1, end - 1);

        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        return solve(preorder, postorder, 0, preorder.size() - 1);
    }
};