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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*temp=head;
        int n;
        int cnt=0;
        ListNode*first;
        ListNode*second;
        while(temp){
            if(cnt==k-1){
                first=temp;
            }
            temp=temp->next;
            cnt++;

        }
        n=cnt-k+1;
        temp=head;
        cnt=0;
        while(temp){
            if(cnt==n-1){
                second=temp;
            }
            temp=temp->next;
            cnt++;
        }

        swap(first->val,second->val);
        return head;

    }
};