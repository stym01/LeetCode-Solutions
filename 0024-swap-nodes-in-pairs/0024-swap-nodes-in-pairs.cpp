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

    ListNode*swap(ListNode*first){
        if(first==NULL || first->next==NULL) return first;
        ListNode*second=first->next;
        ListNode*front=second->next;
        second->next=first;
        first->next=front;
        return second;
    }

    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        head=swap(head);
        ListNode*temp=head->next->next;
        ListNode*prev=head->next;
        while(temp){
            ListNode*current=swap(temp);
            prev->next=current;
            if(current==NULL || current->next==NULL) return head;
            temp=current->next->next;
            prev=current->next;
        }
        return head;
    }
};