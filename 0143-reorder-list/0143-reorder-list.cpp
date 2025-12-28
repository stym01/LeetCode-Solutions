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

    void print(ListNode*head){
        ListNode*temp=head;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;

    }

    void reorderList(ListNode* head) {
        ListNode*mid=findMiddle(head);
        ListNode*middle=mid->next;
        mid->next=NULL;
        ListNode*reversed=reverse(middle);

        ListNode*temp=head;
        
        while(reversed){
            ListNode*front=temp->next;
            temp->next=reversed;
            reversed=reversed->next;
            temp->next->next=front;
            temp=front;
        }
        // if(temp) 
        
    }
};