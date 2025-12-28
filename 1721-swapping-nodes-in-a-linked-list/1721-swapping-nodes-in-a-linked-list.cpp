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

    ListNode*findLast(ListNode*slow,ListNode*temp){
        while(temp){
            slow=slow->next;
            temp=temp->next;
        }
        return slow;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*temp=head;
        int cnt=1;

        while(temp){
            if(cnt==k){
                ListNode*firstNode=temp;
                ListNode*slow=head;
                ListNode*lastNode=findLast(slow,temp->next);
                swap(firstNode->val,lastNode->val);
                return head;
            }
            cnt++;
            temp=temp->next;
        }     
        return NULL;

    }
};