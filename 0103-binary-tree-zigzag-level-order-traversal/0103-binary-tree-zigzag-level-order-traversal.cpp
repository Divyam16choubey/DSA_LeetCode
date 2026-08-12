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
    void levelOrder(TreeNode* root, vector<vector<int>> &ans){
        
        stack<TreeNode*> l; // L to R
        stack<TreeNode*> r; // R to L

        l.push(root);

        while(!r.empty() || !l.empty()){
            vector<int> level;
            if(!r.empty()){
                while(!r.empty()){
                    TreeNode* temp = r.top();
                    r.pop();
                    level.push_back(temp->val);

                    if(temp->right)
                        l.push(temp->right);
                    if(temp->left)
                        l.push(temp->left);
                    
                }
            }
            else{
                while(!l.empty()){
                    TreeNode* temp = l.top();
                    l.pop();
                    level.push_back(temp->val);

                    if(temp->left)
                        r.push(temp->left);
                    if(temp->right)
                        r.push(temp->right);
                }
            }
            ans.push_back(level);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if(root==NULL)
            return ans;

        levelOrder(root, ans);
        return ans;
    }
};