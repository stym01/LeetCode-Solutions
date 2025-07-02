/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* root=new Node(node->val);
        map<Node*,Node*>mpp;
        mpp[node]=root;
        queue<Node*>q;
        map<Node*,int>vis;
        vis[node]=1;
        q.push(node);
        while(!q.empty()){
            Node*temp=q.front();
            q.pop();
            Node*temp2=new Node(temp->val);
            if(mpp.find(temp)==mpp.end()){
                mpp[temp]=temp2;
            }
            else temp2=mpp[temp];
            for(auto it:temp->neighbors){
                Node*adjNode=it;
                if(mpp.find(adjNode)==mpp.end()){
                    mpp[adjNode]=new Node(adjNode->val);
                }
                temp2->neighbors.push_back(mpp[adjNode]);
                if(vis[it]==0) {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return root;
    }
};