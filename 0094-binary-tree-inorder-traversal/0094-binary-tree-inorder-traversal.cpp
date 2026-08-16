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
        if(root==NULL)
            return ans;

        stack<TreeNode*> s;
        stack<bool> vis;
        s.push(root);
        vis.push(0);

        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            bool flag = vis.top();
            vis.pop();

            if(!flag){
                if(temp->right){
                    s.push(temp->right);
                    vis.push(0);
                }
                s.push(temp);
                vis.push(1);
                if(temp->left){
                    s.push(temp->left);
                    vis.push(0);
                }
            }
            else
                ans.push_back(temp->val);
        }
        return ans;
    }
};