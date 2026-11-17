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

 class ValidBST{
    public:
    bool BST;
    int min, max, sum;
    ValidBST(){
        BST = 1;
        min = INT_MAX;
        max = INT_MIN;
        sum = 0;
    }
 };
class Solution {
public:
    ValidBST *find(TreeNode* root, int &maxSum){
        if(root==NULL){
            return new ValidBST();
        }
        ValidBST *left = find(root->left, maxSum);
        ValidBST *right = find(root->right, maxSum);

        if(left->BST && right->BST && left->max < root->val && right->min > root->val){
            ValidBST *head = new ValidBST();
            head->min = min(left->min, root->val);
            head->max = max(root->val, right->max);
            head->sum = left->sum + right->sum + root->val;
            maxSum = max(maxSum ,head->sum);
            return head;
        }
        else{
            ValidBST *head = new ValidBST();
            head->BST = 0;
            return head;
        }
    }
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        find(root, maxSum);
        return maxSum;
    }
};