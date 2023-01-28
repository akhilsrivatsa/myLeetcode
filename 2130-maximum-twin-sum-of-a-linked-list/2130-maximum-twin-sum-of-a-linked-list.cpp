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
    int maxSum = 0;
    void bfs(ListNode * head1 , ListNode * &head2){

        if(head1){

            bfs(head1->next, head2);
            maxSum = max(maxSum, head1->val + head2 -> val);
            head2 = head2->next;
        }
    }
    int pairSum(ListNode* head) {
        
        bfs(head, head);
        return maxSum;
    }
};