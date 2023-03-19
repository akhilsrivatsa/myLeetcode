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
    int deepestLeavesSum(TreeNode* root) {

        queue<TreeNode*> q;

        q.push(root);
        int ans = 0;

        while(!q.empty()){

            int x = q.size();
            ans = 0;
            for(int i = 0; i < x; i++){

                TreeNode *ele = q.front();
                q.pop();

                ans += ele->val;
                if(ele->left){
                    q.push(ele->left);
                }

                if(ele->right){
                    q.push(ele->right);
                }
            }
        }

        return ans;

        
    }
};