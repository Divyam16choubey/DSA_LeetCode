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
    int find(vector<int> in, int target, int start, int end){
        for(int i=start; i<=end; i++){
            if(in[i] == target)
                return i;
        }
        return -1;
    }

    TreeNode* tree(vector<int> in, vector<int> post, int inStart, int inEnd, int index){
        if(inStart>inEnd)
            return NULL;
        TreeNode* root = new TreeNode(post[index]);
        int pos = find(in, post[index], inStart, inEnd);
        root->right = tree(in, post, pos+1, inEnd, index-1);
        root->left = tree(in, post, inStart, pos-1, index-(inEnd-pos)-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return tree(inorder, postorder, 0, n-1, n-1);
    }
};