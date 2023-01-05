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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        queue<TreeNode*> q;

        if(!root) return ans;
        q.push(root);

        while(!q.empty()){

            int x = q.size();
            cout << x << endl;
            vector<int> temp;
            for(int i = 0; i < x; i++){

                TreeNode* front = q.front();
                q.pop();
                temp.push_back(front -> val);
           
                if(front->left) {
                     cout << front->left -> val << endl;
                    q.push(front->left);
                }
                if(front->right) {
                    cout << front->right -> val << endl;
                    q.push(front->right);
                }

            }
            cout << q.size();
            ans.push_back(temp);
        }

        return ans;
        
    }
};