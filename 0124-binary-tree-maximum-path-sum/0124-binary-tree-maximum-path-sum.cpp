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
    int pathSum(TreeNode* root, int &sum) {
        if(root == NULL)
            return 0;

        //Ignore negative contributions
        int left = max(0, pathSum(root->left, sum));
        int right = max(0, pathSum(root->right, sum));

        //Update maximum path at every node
        sum = max(sum, root->val + left + right);

        // Return maximum one-sided path
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        pathSum(root, sum);
        return sum;
    }
};