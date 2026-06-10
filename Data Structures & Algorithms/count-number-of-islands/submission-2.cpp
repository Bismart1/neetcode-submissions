class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>>q;
        int ans=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
               if(grid[i][j]=='1'){
                ans++;
                q.push({i,j});
                while(!q.empty()){
                    auto node=q.front();
                    q.pop();
                    int r=node.first;
                    int c=node.second;
                    if(r<0||r>rows-1||c<0||c>cols-1||grid[r][c]=='0') continue;
                    grid[r][c]='0';
                    q.push({r-1,c});
                     q.push({r+1,c});
                      q.push({r,c-1});
                       q.push({r,c+1});
                
                }

               }
            }
        }
        return ans;
    }
};
