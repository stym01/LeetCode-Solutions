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

    int gcd(int m,int n){
        if(n==0) return m;
        return gcd(n,m%n);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*current=head;
        while(current->next){
            ListNode*front=current->next;
            ListNode*gcdPointer=new ListNode(gcd(current->val,front->val),front);
            current->next=gcdPointer;
            current=front;
        }
        return head;
    }
};