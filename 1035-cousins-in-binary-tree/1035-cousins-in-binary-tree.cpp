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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        int k=0;
        int d1=-1;
        int d2=-1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                if(temp->val==x) d1=k;
                if(temp->val==y) d2=k;
                if(d1!=-1 && d2!=-1) break; 
                if(temp->left && temp->right){
                    if(temp->left->val==x && temp->right->val==y) return 0;
                    if(temp->right->val==x && temp->left->val==y) return 0;
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            k++;
        }
        cout<<d1<<" "<<d2;
        if(d1!=d2) return 0;
        return 1;
    }
};