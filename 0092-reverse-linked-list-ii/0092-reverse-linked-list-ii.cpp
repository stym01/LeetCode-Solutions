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
    
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(head->next==NULL) return head;
        ListNode*temp=head;
        ListNode*left;
        int cnt=1;
        ListNode*right;
        while(temp){
            if(cnt==l){
                left=temp;
            }
            if(cnt==r){
                right=temp;
                break;
            }
            temp=temp->next;
            cnt++;
        }

        temp=head;
        ListNode*prev=NULL;
        while(temp){
            if(temp==left){
                ListNode*front=right->next;
                right->next=NULL;
                ListNode*reversed=reverse(left);
                if(prev!=NULL)
                    prev->next=reversed;
                else head=reversed;
                left->next=front;
                return head;
            }
            prev=temp;
            temp=temp->next;
        }
        return NULL;
    }
};