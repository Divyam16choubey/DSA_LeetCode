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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL)  return {};

        //col, row, and value
        map<int, map<int, multiset<int>>> mp;
        queue<TreeNode*> q;
        queue<int> index;
        queue<int> level;
        q.push(root);
        index.push(0);
        level.push(0);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();
            int row = level.front();
            level.pop();

            mp[pos][row].insert(temp->val);

            if(temp->left){
                q.push(temp->left);
                index.push(pos-1);
                level.push(row+1);
            }
            if(temp->right){
                q.push(temp->right);
                index.push(pos+1);
                level.push(row+1);
            }
        }
        vector<vector<int>> ans;

        for(auto &col: mp){
            vector<int> temp;

            for(auto &row: col.second){
                for(int val: row.second)
                    temp.push_back(val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};