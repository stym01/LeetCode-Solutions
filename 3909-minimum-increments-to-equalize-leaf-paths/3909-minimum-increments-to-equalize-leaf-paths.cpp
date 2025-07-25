class Solution {
public:
    int cnt=0;

    long long dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&cost,int n){
        vis[node]=1;
        map<long long,int>mpp;
        long long maxi=-1e9;
        for(auto it:adj[node]){
            if(!vis[it]){
                long long val=dfs(it,adj,vis,cost,n);
                
                maxi=max(maxi,val);
                mpp[val]++;
            }
        }

        if(maxi==-1e9) return cost[node];

        for(auto it:mpp){
            if(it.first!=maxi) cnt+=it.second;
        }

        return maxi+cost[node];



    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,cost,n);
            }
        }

        return cnt;
    }
};