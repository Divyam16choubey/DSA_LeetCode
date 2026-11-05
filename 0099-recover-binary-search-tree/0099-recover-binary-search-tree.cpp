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
    void recoverTree(TreeNode* root) {
        TreeNode* cur;
        TreeNode *first=NULL, *second = NULL, *prev=NULL, *present=NULL;

        while(root){
            if(root->left==NULL){
                prev = present;
                present = root;
                if(prev && prev->val > present->val){
                    if(first == NULL)
                        first = prev;
                    second = present;
                }
                root = root->right;
            }
            else{
                cur = root->left;
                while(cur->right && cur->right!=root)
                    cur = cur->right;
                if(cur->right == NULL){
                    cur->right = root;
                    root = root->left;
                }
                else{
                    cur->right = NULL;
                    prev = present;
                    present = root;
                    if(prev && prev->val > present->val){
                        if(first==NULL)
                            first = prev;
                        second = present;
                    }
                    root = root->right;
                }
            }
        }
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};