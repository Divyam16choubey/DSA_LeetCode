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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;

        while(root){
            //left subtree doesn't exists
            if(root->left==NULL){
                ans.push_back(root->val);
                root = root->right;
            }
            //left subtree exists
            else{
                TreeNode* cur = root->left;
                while(cur->right!=NULL && cur->right != root)
                    cur = cur->right;
                
                if(cur->right==NULL){
                    cur->right = root;
                    root = root->left;
                }
                else{
                    cur->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return ans;
    }
};