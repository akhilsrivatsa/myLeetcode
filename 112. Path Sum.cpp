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

    bool dfs(TreeNode * root, int sum){


        if(root == NULL) return false;

        if(root->left == NULL && root-> right == NULL && root -> val == sum){

            return true;
        }

        if(root -> left == NULL && root -> right == NULL) return false;

       return dfs(root->left, sum - (root -> val)) || dfs(root->right, sum - (root -> val)); 

    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        return dfs(root, targetSum);
    }
};