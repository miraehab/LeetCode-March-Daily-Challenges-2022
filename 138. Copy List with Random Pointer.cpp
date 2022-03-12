/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        map<Node*, Node*> nodes;
        Node* tmp = new Node(head->val);
        nodes[head] = tmp;
        Node* head_tmp = tmp;
        Node* curr = head;
        while(curr->next != NULL){
            tmp->next = new Node(curr->next->val);
            nodes[curr->next] = tmp->next;
            curr = curr->next;
            tmp = tmp->next;
        }
        tmp = head_tmp;
        curr = head;
        while(curr != NULL && tmp != NULL){
            if(curr->random == NULL) tmp->random = NULL;
            else{
                tmp->random = nodes[curr->random];
                cout<<tmp->random->val<<endl;
            }
            curr = curr->next;
            tmp = tmp->next;
        }
        return head_tmp;
    }
};