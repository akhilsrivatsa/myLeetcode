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
    int helper(TreeNode* root){

        if(!root){
            return 0;
        }
        int leftDepth = helper(root->left);
        int rightDepth = helper(root->right);

        if(leftDepth == -1 || rightDepth == -1){
            return -1;
        } 
        if(abs(leftDepth - rightDepth) > 1){
            return -1;
        }
        return 1 + max(leftDepth, rightDepth);
    }
    bool isBalanced(TreeNode* root) {

        return helper(root) == -1 ? 0 : 1;
        
    }
};