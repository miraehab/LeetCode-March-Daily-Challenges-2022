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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp = new ListNode(0, head);
        ListNode* left = tmp;
        ListNode* right = head;
        while(right != NULL){
            if(right->next != NULL && right->val == right->next->val){
                while(right->next != NULL && right->val == right->next->val){
                    right = right->next;
                }
                left->next = right->next;
            }else{
                left = left->next;
            }
            
            right = right->next;
        }
        return tmp->next;
    }
};