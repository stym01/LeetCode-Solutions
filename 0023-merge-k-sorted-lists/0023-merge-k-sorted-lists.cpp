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

    ListNode* merge(ListNode*left,ListNode* right){
        ListNode*dummyNode=new ListNode(-1);
        ListNode*temp=dummyNode;
        while(left!=NULL && right!=NULL){
            if(left->val<=right->val){
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
            else{
                temp->next=right;
                right=right->next;
                temp=temp->next;
            }
        }
        if(left){
            temp->next=left;
        }
        else{
            temp->next=right;
        }
        return dummyNode->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;
        if(k==1) return lists[0];
        ListNode*head=lists[0];
        for(int i=1;i<k;i++){
            head=merge(head,lists[i]);
        }
        return head;
    }
};