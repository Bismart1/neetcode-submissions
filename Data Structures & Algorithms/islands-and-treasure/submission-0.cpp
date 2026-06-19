class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int r=node.first;
            int c=node.second;
            if( r-1>=0 && grid[r-1][c]==2147483647 ){
                grid[r-1][c]=grid[r][c]+1;
                q.push({r-1,c});
            }
              if(r+1<rows && grid[r+1][c]==2147483647){
                grid[r+1][c]=grid[r][c]+1;
                q.push({r+1,c});
            }
              if(c-1>=0 && grid[r][c-1]==2147483647){
                grid[r][c-1]=grid[r][c]+1;
                q.push({r,c-1});
            }
              if(c+1<cols && grid[r][c+1]==2147483647){
                grid[r][c+1]=grid[r][c]+1;
                q.push({r,c+1});
            }
        }
    }
};
