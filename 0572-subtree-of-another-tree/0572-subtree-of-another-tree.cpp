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

    bool dfs(TreeNode*root,TreeNode*subRoot){
        if(subRoot==NULL && root==NULL) return true;
        if(root==NULL) return false;
        if(subRoot==NULL) return false;
        if(root->val!=subRoot->val) return false;
        return dfs(root->left,subRoot->left) && dfs(root->right,subRoot->right);
    }

    bool f(TreeNode*root,TreeNode*subRoot){
        if(root==NULL) return false;
        if(dfs(root,subRoot)) return true;
        return f(root->left,subRoot) || f(root->right,subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return f(root,subRoot);
    }
};