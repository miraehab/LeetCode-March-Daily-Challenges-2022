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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        int size = 0;
        bool flag = 1;
        ListNode* tmp = head;
        ListNode* head_t = tmp;
        while(flag){
            ++size;
            if(tmp->next == NULL){
                tmp->next = head;
                flag = 0;
            }
            tmp = tmp->next;
        }
        k = k%size;
        for(int i = 1; i<=size-k; ++i){
            if(i == size-k){
                head_t = tmp->next;
                tmp->next = NULL;
            }
            tmp = tmp->next;
        }
        return head_t;
    }
};