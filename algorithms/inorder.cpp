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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> traversalOrder;

        helper(root, &traversalOrder);
        return traversalOrder;
    }

    void helper(TreeNode *node, vector<int> *traversalOrder)
    {
        if (!node)
            return;

        helper(node->left, traversalOrder);
        traversalOrder->push_back(node->val);
        helper(node->right, traversalOrder);
    }
};