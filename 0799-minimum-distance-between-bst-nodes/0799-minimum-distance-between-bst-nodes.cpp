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
int prev=-1e9;

    void f(TreeNode*root,int &mini){
        if(root==NULL) return;
        f(root->left,mini);
        mini=min(mini,root->val-prev);
        prev=root->val;
        f(root->right,mini);
    }

    int minDiffInBST(TreeNode* root) {
        int mini=1e9;
        f(root,mini);
        return mini;
    }
};