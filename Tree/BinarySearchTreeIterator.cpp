
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
class BSTIterator
{
public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root)
    {
        build(root);
    }

    int next()
    {
        auto x = s.top();
        s.pop();
        build(x->right);
        return x->val;
    }

    bool hasNext()
    {
        return !s.empty();
    }
    void build(TreeNode *node)
    {
        // put elements of the left
        while (node)
        {
            s.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */