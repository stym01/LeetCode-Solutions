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
    ListNode* doubleIt(ListNode* head) {
        ListNode*current=head;
        bool carry=0;
        
        if(head->val+head->val>=10){
            ListNode*temp=new ListNode(1);
            temp->next=head;
            head=temp;
        }

        while(current->next){
            ListNode*front=current->next;
            int val=current->val+current->val;
            current->val=val%10;
            if(front->val+front->val>=10) current->val++;
            current=current->next;
        }
        
        current->val=(current->val+current->val)%10;
        return head;

    }
};