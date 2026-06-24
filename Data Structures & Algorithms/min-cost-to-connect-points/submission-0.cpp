class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //prim's algorithm is used here 
        int n = points.size();
        vector<int>mindist(n,INT_MAX);
        vector<bool>visited(n,false);
        int ans=0;
        mindist[0]=0;
        for(int i=0;i<n;i++){
            int u=0;
            while(visited[u]) u++;
            for (int j=0;j<n;j++){
                if(!visited[j] && mindist[j]<mindist[u]){
                    u=j;
                }
            }
            visited[u]=true;
            ans=ans+mindist[u];
            for(int j=0;j<n;j++){
                if(visited[j]) continue;
                int dist=abs(points[u][0]-points[j][0])+abs(points[u][1]-points[j][1]);
                mindist[j]=min(dist,mindist[j]);
            }
        }
        return ans;
    }
};