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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int smallest=-1;
        int largest=-1;
        int maxi=-1;
        int miniDist=1e9;
        if(head==NULL || head->next==NULL) return {-1,-1};
        ListNode*temp=head->next;
        ListNode*prev=head;
        int cnt=1;

        while(temp->next){
            ListNode*front=temp->next;
            if((temp->val>prev->val && temp->val>front->val) ||(temp->val<prev->val && temp->val<front->val) ){
                if(smallest==-1) {
                    smallest=cnt;
                    maxi=cnt;
                }
                else{
                    miniDist=min(miniDist,cnt-maxi);
                    maxi=cnt;
                }
            }
            cnt++;
            prev=temp;
            temp=temp->next;
        }
        if(miniDist==1e9) return {-1,-1};
        return { miniDist, maxi-smallest};
    }
};