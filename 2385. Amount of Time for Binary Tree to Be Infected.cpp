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
    void fill(TreeNode* root, TreeNode* parent,  map<TreeNode*,TreeNode*> &mp, int start, TreeNode* &val)
    {

        if(root == NULL) return;

        mp[root] = parent;

        if(root -> val == start){
            val = root;
        }

        fill(root->left, root, mp, start, val);
        fill(root->right, root, mp, start, val);
    }
    int amountOfTime(TreeNode* root, int start) {

        map<TreeNode*,TreeNode*> parent;
        TreeNode* val; 
        fill(root, NULL , parent, start, val);
        int time = 0;
        queue<TreeNode *> q;
        set<TreeNode *> s;
        q.push(val);
        s.insert(val);
        while(!q.empty()){


            int p = q.size();
            for(int i = 0; i < p; i++){

                TreeNode* temp = q.front();
                cout << temp->val << endl;
                q.pop();

                if(temp->left && s.find(temp->left) == s.end()) {

                    q.push(temp ->left); 
                    s.insert(temp->left);   
                }
                if(temp->right && s.find(temp->right) == s.end()){
                    q.push(temp->right);
                    s.insert(temp->right);   
                } 
                if(parent[temp] &&s.find(parent[temp]) == s.end()){
                    q.push(parent[temp]);  
                     s.insert(parent[temp]);    
                } 

            }

            time++;
        }

       

        return time  - 1;
        

        
    }
};