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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<pair<TreeNode*,ListNode*>,bool>mpp;
    bool f(TreeNode*root,ListNode*head,ListNode*start){
        if(head==NULL) return true;
        if(mpp.find({root,head})!=mpp.end()) return mpp[{root,head}];
        if(root==NULL) return false;
        bool matched=0;
        bool not_matched=0;
        if(root->val==head->val){
            matched= f(root->left,head->next,start) || f(root->right,head->next,start);
        }
        not_matched=f(root->left,start,start) || f(root->right,start,start);
        return mpp[{root,head}]=matched || not_matched;
    }   

    bool isSubPath(ListNode* head, TreeNode* root) {
        return f(root,head,head);
    }
};