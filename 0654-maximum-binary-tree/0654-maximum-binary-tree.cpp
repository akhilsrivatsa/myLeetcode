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
    TreeNode* dfs(vector<int> &nums, int left, int right){


        if(left > right){
            return NULL;
        }

        int maxIndex = left;

        for(int i = left; i <= right; i++){
            if(nums[i] > nums[maxIndex]){
                maxIndex = i;
            }
        }

        TreeNode *root = new TreeNode(nums[maxIndex]);
        root -> left = dfs(nums, left, maxIndex - 1);
        root -> right = dfs(nums, maxIndex + 1, right);
        return root;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
        
    }
};