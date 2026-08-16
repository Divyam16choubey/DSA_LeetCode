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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;

        stack<TreeNode*> s;
        stack<int> st;
        s.push(root);

        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();

            st.push(temp->val);

            if(temp->left)
                s.push(temp->left);
            if(temp->right)
                s.push(temp->right);

        }
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};