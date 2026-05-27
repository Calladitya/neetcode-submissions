class Solution {
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>> & grid){
        vis[row][col]=1;//vis jo hoga vo on the  basis of 1 define hoga always ,hmne call kiya h to ye vale row or col visited h 
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;//yaha hamne ek queue banaya h jisme hm row or col ko daal denge 
        q.push({row,col});

        int delr[4]={-1,0,1,0};//for moving row in all four directions
         int delc[4]={0,1,0,-1};//or moving col in all four directions

         while(!q.empty()){//jbtk mera q empty nhi ho jaata tb tk poping chalegi
            row=q.front().first;
            col=q.front().second;

            q.pop();

            for(int i=0;i<4;i++){//new row value or new col value di jaa rahi h
                int nrow=row+delr[i];
                int ncol=col+delc[i];

                if(nrow >=0 &&  nrow <n && ncol >=0 && ncol <m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    //ye condition use hoti h validity ke liye 
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
         }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();//sbse pehele hm len ko intiallize krenge on the basis of ro and col
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));//ye hamne bnaya h ek vis array jiki vajay se hm easily calculate kr sakte h cnt
        int cnt=0;
        for(int row=0;row<n;row++){//ye loop for row basis
            for(int col=0;col<m;col++){//ye h loop for col basis
                if(!vis[row][col] && grid[row][col]=='1'){//yaha hm check kr rahe h ki agr vis nhi h [row][col] or grid [row][col] =1 h mtlb vo value land h ab bs hm ko uske uper iterate krna h 
                    cnt++;//jese hi uper vali condition true hui hm cnt ko bada denge
                    bfs(row,col,vis,grid);//ab hm uske horizontal or vertical components ko bhi check karenge bfs ke under
                }
            }
        }
        return cnt;//at the end no of island were print 
    }
};
