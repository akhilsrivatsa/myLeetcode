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
    void recurse(ListNode* head, ListNode* &ans, int &maxValue){

        if(!head){
            return;
        }

        recurse(head -> next, ans, maxValue);
        if(head->val >= maxValue){
            ListNode *temp = new ListNode(head -> val);
            maxValue = max(head -> val, maxValue);
            temp -> next = ans;
            ans = temp;
        }
        
    }

    ListNode* removeNodes(ListNode* head) {

        ListNode* ans = NULL;
        int maxValue = INT_MIN;
        recurse(head, ans, maxValue);
        return ans;
    }
};