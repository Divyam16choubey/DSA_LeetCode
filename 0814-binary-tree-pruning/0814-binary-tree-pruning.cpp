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
    bool purne(TreeNode* &root){
        if(root==NULL) return false;

        bool left = purne(root->left);
        bool right = purne(root->right);

        if(left==NULL)
            root->left = NULL;
        if(right==NULL)
            root->right = NULL;

        if(root->val==1 || left==true || right==true)
            return true;
        else
            return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool ans = purne(root);
        if(ans)
            return root;
        else
            return NULL;
    }
};