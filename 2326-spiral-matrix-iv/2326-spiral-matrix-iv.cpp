/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        

        int sr = 0, sc = 0;
        int er = m - 1, ec = n - 1;
        vector<vector<int>> matrix(m, vector<int> (n, -1));

        while(sr <= er && sc <= ec){

            for(int i = sc ; i <= ec ; i++){

                if(head){
                    matrix[sr][i] = head -> val;
                    head = head -> next;
                }
                
            }
            sr++;

            for(int i = sr ; i <= er; i++){

                if(head){
                     matrix[i][ec] = head -> val;
                     head = head -> next;
                }
               
            }
            ec--;


            for(int i = ec ; i >= sc && sr <= er; i--){

                if(head){
                    matrix[er][i] = head -> val;
                    head = head -> next;
                }
                
            }

            er--;


            for(int i = er ; i >= sr && sc <= ec; i--){

                if(head){
                    matrix[i][sc] = head -> val;
                    head = head -> next;
                }
                
            }
            sc++;
        }

        return matrix;
    }
};