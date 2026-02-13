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
class Solution {
public:
    bool checkValidity(TreeNode * root,long long lowerValue, long long upperValue)
    {
        if(root == NULL) return true;
        if(root->val >= upperValue || root->val <= lowerValue) return false;
        return (checkValidity(root->left,lowerValue,root->val) && checkValidity(root->right,root->val,upperValue));
    }
    bool isValidBST(TreeNode* root) {
        return checkValidity(root,LLONG_MIN,LLONG_MAX);
    }
};