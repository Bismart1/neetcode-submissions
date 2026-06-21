class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<rows;i++){
            if(board[i][0]=='O') q.push({i,0});
            if(board[i][cols-1]=='O') q.push({i,cols-1});
        }
        for(int j=0;j<cols;j++){
            if(board[0][j]=='O') q.push({0,j});
            if(board[rows-1][j]=='O') q.push({rows-1,j});
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int r=node.first;
            int c=node.second;
            if(r<0 || r>rows-1 || c<0 || c>cols-1 || board[r][c]!='O'){
                continue;
            }
            board[r][c]='&';
            q.push({r-1,c});
            q.push({r+1,c});
            q.push({r,c-1});
            q.push({r,c+1});
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='&') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};
