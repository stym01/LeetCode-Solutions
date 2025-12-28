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

    ListNode*findMiddle(ListNode*head){
        ListNode*fast=head->next;
        ListNode*slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode*reverse(ListNode*head){
        if(head==NULL || head->next==NULL) return head;
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

    int pairSum(ListNode* head) {
        ListNode*middle=findMiddle(head);
        cout<<middle->val;
        ListNode*reversed=reverse(middle->next);
        ListNode*temp=head;
        int maxi=-1e9;
        while(reversed){
            int sum=reversed->val+temp->val;
            reversed=reversed->next;
            temp=temp->next;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};