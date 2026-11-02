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
    bool isBST(TreeNode* root, long long &prev){
        if(root==NULL)
            return 1;
        bool left = isBST(root->left, prev);

        if(left==0) 
            return 0;
        if(root->val<=prev)
            return 0;
        prev = root->val;
        return isBST(root->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return isBST(root, prev);
    }
};