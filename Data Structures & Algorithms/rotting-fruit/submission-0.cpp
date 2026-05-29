class Solution {
    int bfs(queue<pair<pair<int,int>,int>>& q,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();

        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        int ans=0;

        while(!q.empty()){
           int row = q.front().first.first;
           int col = q.front().first.second;
           int time = q.front().second;
             
             
                q.pop();
                ans=max(ans,time);

            for(int i=0;i<4;i++){
                int nrow=row+delr[i];
                int ncol=col+delc[i];
                

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }
        return ans;

    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
         int n=grid.size();
          int m=grid[0].size();

          queue<pair<pair<int,int>,int>> q;

          for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==2){
                    q.push({{row,col},0});
                }
            }
          }
          int ans=bfs(q,grid);
          for(int row=0; row<n; row++)
        {
            for(int col=0; col<m; col++)
            {
                if(grid[row][col] == 1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
