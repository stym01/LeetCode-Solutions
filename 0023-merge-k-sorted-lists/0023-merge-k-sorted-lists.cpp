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

    ListNode*merge(ListNode*temp1,ListNode*temp2){
        ListNode*result=new ListNode(0);
        ListNode*ans=result;
        while(temp1 && temp2){
            if(temp1->val>temp2->val){
                result->next=temp2;
                result=result->next;
                temp2=temp2->next;
            }
            else{
                result->next=temp1;
                result=result->next;
                temp1=temp1->next;
            }
        }
        if(temp1){
            result->next=temp1;
        }
        if(temp2) result->next=temp2;

        return ans->next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0) return NULL;

        // ListNode*result=lists[0];
        for(int i=0;i<lists.size()-1;i++){
            lists[i+1]=merge(lists[i],lists[i+1]);
        }
    
        return lists[lists.size()-1];

    }
};