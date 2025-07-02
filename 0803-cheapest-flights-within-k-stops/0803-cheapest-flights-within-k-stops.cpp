class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>vis(n,0);
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});

        while(!q.empty()){
            int cost=q.front().first;
            int node=q.front().second.first;
            int stops=q.front().second.second;
            q.pop();
            // if(node==dst && stops<=k) return cost;
            if(stops>k) continue;

            for(auto it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                if(cost+wt<dist[adjNode]){
                    q.push({cost+wt,{adjNode,stops+1}});
                    dist[adjNode]=cost+wt;
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
    
};