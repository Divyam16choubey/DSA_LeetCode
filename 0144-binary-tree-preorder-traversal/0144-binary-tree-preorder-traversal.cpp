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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        //Using Morris Traversal

        TreeNode* cur = root;

        while(cur != NULL){
            //left child not exists
            if(cur->left == NULL){
                ans.push_back(cur->val);
                cur = cur->right;
            }
            //left child exists
            else{
                TreeNode* temp = cur->left;
                while(temp->right!=NULL && temp->right !=cur){
                    temp= temp->right;
                }
                //first time visiting cur node
                if(temp->right==NULL){
                    ans.push_back(cur->val);
                    temp->right = cur;
                    cur = cur->left;
                }
                else{ //visiting 2nd time cur node
                    temp->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};