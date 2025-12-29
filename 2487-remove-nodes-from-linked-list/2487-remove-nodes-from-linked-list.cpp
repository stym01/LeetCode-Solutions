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

    ListNode*reverse(ListNode*head){
        ListNode*current=head;
        ListNode*prev=NULL;
        while(current){
            ListNode*front=current->next;
            current->next=prev;
            prev=current;
            current=front;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        
        ListNode*reversed=reverse(head);
        int maxi=-1e9;
        head=reversed;
        ListNode*prev=NULL;
        while(reversed){
            int val=reversed->val;
            if(val<maxi){
                prev->next=reversed->next;
            }
            else
                prev=reversed;
            reversed=reversed->next;
            maxi=max(maxi,val);
        }

        return reverse(head);


    }
};