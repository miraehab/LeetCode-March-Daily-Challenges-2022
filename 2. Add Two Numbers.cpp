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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp = new ListNode;
        ListNode* head = tmp;
        int c = 0;
        while(l1 != NULL || l2 != NULL){
            int i1 = l1 ? l1->val : 0;
            int i2 = l2 ? l2->val : 0;
            tmp->next = new ListNode((i1+i2+c)%10);
            c = (i1+i2+c)/10;
            tmp = tmp->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(c == 1){
            tmp->next = new ListNode(c);
            tmp = tmp->next;
        }
        return head->next;
    }
};