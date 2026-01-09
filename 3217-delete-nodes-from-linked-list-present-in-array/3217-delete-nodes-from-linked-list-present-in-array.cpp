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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        ListNode*prev=head;
        ListNode*current=head->next;
        while(current){
            if(mpp[current->val]>0) {
                ListNode*del=current;
                prev->next=current->next;
                current=current->next;
                delete(del);

            }
            else{
                prev=current;
                current=current->next;
            }
        }
        cout<<"JIo";

        if(mpp[head->val]>0) {
            ListNode*del=head;
            head=head->next;
            // delete del;
        }
        cout<<"JI";
        return head;
    }
};