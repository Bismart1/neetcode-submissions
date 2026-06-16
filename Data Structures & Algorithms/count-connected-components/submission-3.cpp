class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
    
        vector<int>parents(n+1);
        int ans=n;
        for(int i=0;i<n;i++){
            parents[i]=i;
        }
        for(auto edge: edges){
            auto u=edge[0];
            auto v=edge[1];
            while(parents[u]!=u) u=parents[u];
            while(parents[v]!=v) v=parents[v];
            if(u!=v){
                parents[u]=v;
                ans--;
            }
        }
        return ans;
    }
};
