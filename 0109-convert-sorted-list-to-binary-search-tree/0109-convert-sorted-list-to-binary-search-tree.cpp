class Solution {
public:

    pair<ListNode*,ListNode*> findMiddle(ListNode*head){
        ListNode*fast=head;
        ListNode*slow=head;
        ListNode*prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        if(prev!=NULL)
            prev->next=NULL;
        return {slow,prev};
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;



        pair<ListNode*,ListNode*>p=findMiddle(head);
        ListNode*middle=p.first;
        ListNode*left=p.second;
        TreeNode*rightt;
        // if(middle->next!=NULL){
        //     ListNode*right=middle->next;
        //     rightt=new TreeNode(right->val);
        // }
        // else{
        //     rightt=NULL;
        // }
        TreeNode*leftt=NULL;
        // if(left!=NULL){
        //     leftt==new TreeNode(left->val);
        //     cout<<"L";
        // }
        // else{
        //     leftt=NULL;
        // }
        if(middle!=head && middle!=NULL && middle!=head->next)
            leftt=sortedListToBST(head);

        rightt=sortedListToBST(middle->next);

        TreeNode*root=new TreeNode(middle->val,leftt,rightt);
        return root;

    }
};