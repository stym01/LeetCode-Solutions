class dsu{
private:
public:
    vector<int>parent,size,rank;

    dsu(int n){
        parent.resize(n);
        size.resize(n,1);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findUlPar(int u){
        if(u==parent[u]) return u;
        return parent[u]=findUlPar(parent[u]);
    }
    
    void unionBySize(int u,int v){
        int pu=findUlPar(u);
        int pv=findUlPar(v);
        if(pu==pv) return;

        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }

    }

    void unionByRank(int u,int v){
        int pu=findUlPar(u);
        int pv=findUlPar(v);
        if(pu==pv) return;

        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
            rank[pu]++;
        }
        else{
            parent[pu]=pv;
            size[pv]++;
        }

    }

};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        dsu ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    ds.unionByRank(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cnt++;
        }
        return cnt;
    }
};