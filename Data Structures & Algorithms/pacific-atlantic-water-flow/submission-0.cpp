class Solution {

    bool bfs(int row ,int col,vector<vector<int>>& vis,vector<vector<int>>& heights){
         int n=heights.size();
         int m=heights[0].size();
         

         queue<pair<int,int>>q;
         q.push({row,col});
          vis[row][col]=1;
         

          bool pacefic=false;
          bool artic= false;

         int delr[]={-1,0,1,0};
         int delc[]={0,1,0,-1};

         while(!q.empty()){
            row=q.front().first;
            col=q.front().second;

            q.pop();

            if(row==0 || col==0){
                    pacefic=true;
            }
            if(row==n-1 || col==m-1 ){
                    artic=true;
            }
            if(artic && pacefic){
                   return true;
             }


            for(int i=0;i<4;i++){
                int nrow=row+delr[i];
                int ncol=col+delc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && 
                   ncol<m && heights[nrow][ncol] <= heights[row][col] 
                   && !vis[nrow][ncol]){

                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
         }
         return false;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>result;
        int n=heights.size();
        int m=heights[0].size();
         for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                vector<vector<int>>vis(n,vector<int>(m,0));
                if(bfs(row,col,vis,heights)){
                    result.push_back({row,col});
                }
            }
         }
         return result;
    }
};
